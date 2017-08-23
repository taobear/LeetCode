/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
 Problem: 		Simplify Path
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/simplify-path/description/
 Tags: 			Stack, String
*/

// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"

#include "leetcode.hpp"

class Solution {
public:
    string simplifyPath(string path) {
    	int len = path.size();

        vector<string> stk;
        int i = 0, j = 0;

        for ( ; j < len; ++j) {
        	if (path[j] == '/' || j == len - 1) 
        	{
        	    string tmp;
        		if (j == len - 1 && path[j] != '/')
        			tmp = path.substr(i, j - i + 1);
        		else
        			tmp = path.substr(i, j - i);

        		if (!tmp.empty()) { 
        			if (tmp == ".") {

        			} else if (tmp == "..") {
        				if (!stk.empty()) stk.pop_back();
        			}
        			else 
        				stk.push_back("/" + tmp);
        		}
        		i = j + 1;
        	} 
        }

        string rslt;
        for (auto & e : stk)
        	rslt += e;
        return stk.empty() ? '/' + rslt : rslt;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	string input1 = "/home/";
	string target1 = "/home";

	string input2 = "/a/./b/../../c/";
	string target2 = "/c";

	string input3 = "/../";
	string target3 = "/";

	string input4 = "/a/.....";
	string target4 = "/a/.....";


	string input5 = "/.././GVzvE/./xBjU///../..///././//////T/../../.././zu/q/e";
	string target5 = "/zu/q/e";

	VERIFY_IS_EQUAL(sln.simplifyPath(input1), target1);
	VERIFY_IS_EQUAL(sln.simplifyPath(input2), target2);
	VERIFY_IS_EQUAL(sln.simplifyPath(input3), target3);
	VERIFY_IS_EQUAL(sln.simplifyPath(input4), target4);
	VERIFY_IS_EQUAL(sln.simplifyPath(input5), target5);
}