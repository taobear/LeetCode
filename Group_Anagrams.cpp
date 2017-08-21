/*
 Author: 		TaoBear
 Update:		Aug 21, 2017
 Problem: 		Group Anagrams
 Difficulty: 	Median
 Source:		https://leetcode.com/problems/group-anagrams/description/
 Tags: 			Hash Table
*/

// Given an array of strings, group anagrams together.

// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
// Return:

// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note: All inputs will be in lower-case.

#include "leetcode.hpp"

int hash_str(string s)
{
	int len = s.size();

	sort(s.begin(), s.end());
	int cnt = 0, digit = 1;
	
	for (int i = 0; i < len; ++i)
	{
		cnt += (s[i] - 'a') * digit;
		digit *= 26;
	}
}

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int size = strs.size();
		vector<vector<string>> rslt;
		map<int, set<int>> map_si;

		for (int i = 0; i < size; ++i)
		{
			int tmp = hash_str(strs[i]);
			map_si[tmp].insert(i); 
		}
		rslt.resize(map_si.size());

		int cnt = 0;
		for (auto & e : map_si)
		{
			for (auto & s : e.second)
				rslt[cnt].push_back(strs[s]);
			cnt++;
		}
		return rslt;
	}
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};

	vector<vector<string>> target = {{"ate", "eat","tea"},
									 {"nat","tan"},
									 {"bat"}};

	VERIFY_IS_EQUAL(sln.groupAnagrams(input), target);
}	