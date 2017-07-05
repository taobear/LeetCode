/*
 Author: 		TaoBear
 Update:		July 2, 2017
 Problem: 		4Sum
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/4sum/#/description
 Tags: 			Array, Hash Table, Two Pointers
*/

// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Note: The solution set must not contain duplicate quadruplets.

// For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

#include "leetcode.hpp"
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		size_t len = nums.size();
		if (len < 4)
			return vector<vector<int>>{};

		set<vector<int>> rst;
		sort(nums.begin(), nums.end());

		size_t n1 = 0, n2 = 0, n3 = 0, n4 = 0;
		int v1 = 0, v2 = 0, v3 = 0, v4 = 0;

		int sum1 = 0, sum2 = 0, sum = 0;
		for (n2 = 1; n2 < len - 2; ++n2) {

			v2 = nums[n2];
			
			n1 = 0;

			while (n1 < n2) {
	

				v1 = nums[n1];
				sum1 = v1 + v2;

				n3 = n2 + 1;
				n4 = len -1;
				int minVal = nums[n3] + nums[n3 + 1];
				int maxVal = nums[n4] + nums[n4 - 1];

				if (minVal + sum1 <= target && maxVal + sum1 >= target)
				{
					while (n3 < n4) 
					{
						v3 = nums[n3];
						v4 = nums[n4];

						sum2 = v3 + v4;
						sum = sum1 + sum2;
						if (sum < target) {
							n3++;
						}
						else if (sum > target) {
							n4--;
						}
						else {
							rst.insert(vector<int>{v1, v2, v3, v4});

							while (++n3 < n4 && nums[n3] == v3);
							while (n3 < --n4 && nums[n4] == v4);
						}
					}
				}
				while (++n1 < n2 && nums[n1] == v1);
			}
        	//++n2;
        	//while (++n2 < len - 2 && nums[n2] == v2);
		}
		return vector<vector<int>>(rst.begin(), rst.end());
	}
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = { 1, 0, -1,  0, -2,  2};
	vector<int> input2 = {-1, 0,  1,  2, -1, -3};
	vector<int> input3 = {-5, 5,  4, -3,  0,  0, 4, -2};

	vector<vector<int>> rst1 = {{-1,  0, 0, 1},
	{-2, -1, 1, 2},
	{-2,  0, 0, 2}};

	vector<vector<int>> rst2 = {{-3, -1,  1, 2}, 
	{-1, -1, 0, 1}};

	vector<vector<int>> rst3 = {{-5, 0, 4, 5},
	{-3, -2, 4, 5}};

	VERIFY_IS_EQUAL(sln.fourSum(input1,  0), rst1);
	VERIFY_IS_EQUAL(sln.fourSum(input2, -1), rst2);
	VERIFY_IS_EQUAL(sln.fourSum(input3,  4), rst3);
}