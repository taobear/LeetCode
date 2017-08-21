/*
 Author: 		TaoBear
 Update:		Aug 21, 2017
 Problem: 		Maximum Subarray
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/maximum-subarray/description/
 Tags: 			Array, Divide and Conquer, Dynamic Programming
*/

// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,-1,2,1] has the largest sum = 6.

#include "leetcode.hpp"

int maxSubArray1(vector<int>& nums)
{
	int len = nums.size();
	int ans = 0, sum = 0;

	for (int i = 0; i < len; ++i) {
		sum += sums[i];
		ans = max(sum, ans);
		sum = max(0, sum);
	}
	return ans;
}

int maxSubArray2(vector<int>& sums)
{

}

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		return maxSubArray1(nums);
	}
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

	int target1 = 6;

	VERIFY_IS_EQUAL(sln.maxSubArray(input1), target1);
}