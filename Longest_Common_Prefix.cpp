/*
 Author: 		TaoBear
 Update:		July 1, 2017
 Problem: 		Longest Common Prefix
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/longest-common-prefix/#/description
 Tags: 			string
*/

// Write a function to find the longest common prefix string amongst an array of strings.


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if (strs.empty()) return "";
        size_t minLen = strs[0].size();;
        for (auto & str : strs)
        	minLen = min(str.size(), minLen);

        size_t pos = 0;
        while (pos < minLen)
        {
        	char c = strs[0][pos];
        	for (auto& str : strs)
        	{
        		if (str[pos] != c)
        			return str[0].substr(0, pos);
        	}
        	pos++;
        	//n = pos + 1;
        }
        return strs[0].substr(0, minLen);
    }
};

int main(int argc, char **argv)
{

}