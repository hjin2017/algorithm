
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



void areFriends(int size,int x,vector<vector<int>> v , vector<vector<int>> &count)
{
	if (x == v.size())return;
	int j = 0;
	vector<int> result;

	result.push_back(v[x][0]);
	result.push_back(v[x][1]);

	for (int j = 0; j < v.size(); j++)
	{
		for (int i = 0; i < result.size() - 1; i += 2)
		{
			if (result[i] == v[j][0] || result[i] == v[j][1]
				|| result[i + 1] == v[j][0] || result[i + 1] == v[j][1])break;
			if (i + 1 != result.size() - 1)continue;
			result.push_back(v[j][0]);
			result.push_back(v[j][1]);
		}
	}

	if (result.size() != size) {
		areFriends(size,x + 1, v, count);
	}
	else{

		int  xcount = 0;
		for (int i = 0; i < count.size(); i++){
			xcount = 0;
			for(int j =0 ; j <result.size()-1; j+=2){
				for (int k = 0; k < result.size() - 1; k += 2) {

					if (count[i][j] == result[k] && count[i][j + 1] == result[k + 1]){
						xcount++;
						break;
					}
				}
			}
			if (xcount == result.size() / 2) {
				result.push_back(-1);
				break;
			}
		}

		if (result[result.size()-1] != -1)
		{
			count.push_back(result);
			areFriends(size,x + 1, v, count);
		}
		else
			areFriends(size,x + 1, v, count);

		
	}
}


int main() {
	vector<vector<int>>result;
	int count = 0;
	 areFriends(4,0, {{ 0, 1 },{ 1,2 },{ 2,3 },{ 3,0 },{ 0,2},
								{ 1,3 }}, result);

	return 0;
}

