/*
 Author: 		TaoBear
 Update:		Aug 26, 2017
 Problem: 		Restore IP Addresses
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/restore-ip-addresses/description/
 Tags: 			Backtracking, String
*/


// Given a string containing only digits, restore it by returning all possible valid IP address combinations.

// For example:
// Given "25525511135",

// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)


#include "leetcode.hpp"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> rslt;
        string tmp;

        helper(rslt, s, s.size(), tmp, 0, 0);
        return rslt;
    }

    void helper(vector<string>& rslt, string &s, int n,
    			 string tmp, int k, int level) {
    	if (level >= 4 || k >= n) {
    		if (k == n && level == 4)
    			rslt.push_back(tmp);
    		return;
    	}
    	string punc = level == 3 ? "" : ".";
    	string comb;

    	for (int i = k; i < n; ++i) {
    		comb = s.substr(k, i - k + 1);
    		if (!isVaild(comb) || i - k + 1 > 3) 
    			break;
    		helper(rslt, s, n, tmp + comb + punc, i + 1, level + 1);
    	}
    }

    bool isVaild(string& str) {
    	int len = str.size();
    	if (len != 1 && str[0] == '0')
    		return false;

    	int val = 0, cnt = 0;
    	while (cnt < len) {
    		val *= 10;
    		val += (str[cnt] - '0');
    		cnt++;
    	}

    	return val <= 255 ? true : false;
    }


};

int main(int argc, char **argv)
{
	Solution sln;

	string input1 = "25525511135";

	vector<string> target1 = {"255.255.11.135", "255.255.111.35"};

	VERIFY_IS_EQUAL(sln.restoreIpAddresses(input1), target1);
}