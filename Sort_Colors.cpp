/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
 Problem: 		Sort Colors
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/sort-colors/description/
 Tags: 			Array, Two Pointers, Sort
*/

// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

// Note:
// You are not suppose to use the library's sort function for this problem.

#include "leetcode.hpp"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;

        for (int i = 0; i < nums.size(); ) {
        	if (nums[i] == 0) {
        		swap(nums[white], nums[i]);
        		white++;
        	} else if (nums[i] == 1) {
        		swap(nums[blue], nums[i]);
        		blue++;
        	} else if (nums[i] == 2) {
				i++;        		
        	}

        	if (white > blue) 
        		blue = white;

        	if (blue > i)
        		i++;
        }	
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {2, 1, 2, 1, 0, 0, 0};

	vector<int> target1 = {0, 0, 0, 1, 1, 2, 2};

	sln.sortColors(input1);

	VERIFY_IS_EQUAL(input1, target1);
}