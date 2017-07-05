/*
 Author: 		TaoBear
 Update:		July 4, 2017
 Problem: 		Implement strStr()
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/implement-strstr/#/description
 Tags: 			String, Two Pointers
*/

// Implement strStr().

// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

int strStr1(string haystack, string needle) 
{
	int N = haystack.size();
	int M = needle.size();
	if (!M) return 0;
	//int rslt = 0;

	for (int i = 0; i <= N - M; ++i) //减掉后的第一个元素
	{
		int j;
		for (j = 0; j < M; ++j) 
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (j == M)
			return i;
	}
	return -1;
}

int strStr2(string haystack, string needle)
{
	
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        
    }
};

int main(int argc, char **argv)
{

}