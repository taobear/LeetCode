/*
 Author: 		TaoBear
 Update:		Aug 30, 2017
 Problem: 		Word Ladder
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/word-ladder/description/
 Tags: 			Breadth First Search
*/

// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

// Only one letter can be changed at a time.
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
// For example,

// Given:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log","cog"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.

// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.
// UPDATE (2017/1/20):
// The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

#include "leetcode.hpp"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        vector<int> visited(len, 0);
        queue<string> q;
        q.push(beginWord);
        int level = 1;

        while (!q.empty()) 
        {
        	queue<string> tmp;
        	while (!q.empty()) 
        	{
        		string str = q.front();
        		q.pop();
        		if (str == endWord) 
        			return level;
        		
        		for (int i = 0; i < len; ++i) 
        		{
        			if (!visited[i] && oneChanged(str, wordList[i]))
        			{
        				visited[i] = 1;
        				tmp.push(wordList[i]);
        			}
        		}
        	}
        	swap(tmp, q);
        	level = level + 1;
        }

        return 0;
    }

    bool oneChanged(const string &lhs, const string &rhs) {
    	int len = lhs.size();
    	int count = 0;
    	for (int i = 0; i < len; ++i) {
    		if (lhs[i] != rhs[i])
    			count++;
    	}

    	return count == 1;
    }


};

int main(int argc, char **argv)
{
	Solution sln;

	string beginWord = "hit";
	string endWord = "cog";

	vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

	VERIFY_IS_EQUAL(sln.ladderLength(beginWord, endWord, wordList), 5);
}