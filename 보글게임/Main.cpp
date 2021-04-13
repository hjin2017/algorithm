
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include "Main.h"

#include<stdio.h>
#include <iostream>
using namespace std;

bool Sword(int y, int x, string &word, int cindex, vector<vector<char>> & table )
{
	if (cindex == word.size())return true;
	bool re = false;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++)
		{
			if (y + i<-1 || x + j<-1 || y + i >= table.size()
				|| x + j >= table[0].size() ||
				table[y][x] == table[y + i][x + j])continue;

			if (table[y + i][x + j] == word[cindex] && re == false)
			{
				re = Sword(y, x, word, cindex + 1, table);
			}

		}
	}
}

bool hasWord(int y, int x, string word)
{
	int cindex = 0;
	vector<vector<char>> table;
	vector<int> res;
	table.resize(5, vector<char>(5,0));
	table = {{ 'U', 'R', 'L', 'P', 'M' },
			  { 'X', 'P', 'R', 'E', 'T' },
			  { 'G', 'I', 'A', 'E', 'T' },
			  { 'X', 'T', 'N', 'Z', 'Y' },	
			  { 'X', 'O', 'Q', 'R', 'S' }};

	if (table[y][x] != word[cindex])return false;
	return Sword(y,x, word, cindex+1, table);
}


int main() {
	
	bool as = hasWord(2,0,"GIRL");
	as;
	return 0;
}

