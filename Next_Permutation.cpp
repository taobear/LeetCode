/*
 Author: 		TaoBear
 Update:		July 5, 2017
 Problem: 		Next Permutation
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/next-permutation/#/description
 Tags: 			Array
*/

// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

// The replacement must be in-place, do not allocate extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

// permutation 			--> 	置换
// lexicographically 	-->		字典的


// 也就是将n个数的排列按大小组合，找出先后次序
#include "leetcode.hpp"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int len = nums.size();

    	if (len < 2) return;

    	int cur = len, j;
    	while (--cur > 0) {
    		if (nums[cur - 1] < nums[cur]) {
    			j = len;
    			while (--j >= cur && nums[j] <= nums[cur - 1]);
    			
    			int tmp = nums[cur - 1];
    			nums[cur - 1] = nums[j];
    			nums[j] = tmp; 

    			reverse(nums.begin() + cur, nums.end());
    			return;
    		}
    	}

    	reverse(nums.begin(), nums.end());
    }
};

int main(int argc, char **argv)
{
	vector<int> input1 = {1, 2, 3};
	vector<int> rslt1 = {1, 3, 2};

	vector<int> input2 = {1, 1};
	vector<int> rslt2 = {1, 1};

	vector<int> input3 = {1, 3, 2};
	vector<int> rslt3 = {2, 1, 3};

	Solution sln;

	sln.nextPermutation(input1);
	sln.nextPermutation(input2);
	sln.nextPermutation(input3);

	VERIFY_IS_EQUAL(input1, rslt1);
	VERIFY_IS_EQUAL(input2, rslt2);
	VERIFY_IS_EQUAL(input3, rslt3);
}