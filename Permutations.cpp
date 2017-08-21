/*
 Author: 		TaoBear
 Update:		June 16, 2017
 Problem: 		Container With Most Water
 Difficulty: 	Median
 Source:		https://leetcode.com/problems/container-with-most-water/#/description
 Tags: 			Array, Two Pointer
*/


// Given a collection of distinct numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include "leetcode.hpp"

// void next_permute(vector<vector<int>>& rslt, vector<int> nums)
// {
// 	int len = nums.size();

// 	if (len < 2) return;

// 	int cur = len, j;
    	
//     while (--cur > 0) {
//     	if (nums[cur - 1] < nums[cur]) {
//     		j = len;
//     		while (--j >= cur && nums[j] <= nums[cur - 1]);
    		
//     		int tmp = nums[cur - 1];
//     		nums[cur - 1] = nums[j];
//     		nums[j] = tmp; 

//    			reverse(nums.begin() + cur, nums.end());
   			
//    			rslt.push_back(nums);
//    			return next_permute(rslt, nums);
   			
//     	}
//     }

//     // reverse(nums.begin(), nums.end());
//     // rslt.push_back(nums);
//     // return next_permute(rslt, nums);
// }

class Solution
{
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> rslt;

		permuteRecursive(nums, 0, rslt);
		return rslt;
	}

	void permuteRecursive(vector<int>& nums, int begin, vector<vector<int>> &rslt)
	{
		if (begin >= nums.size()) {
			rslt.push_back(nums);
			return;
		}

		for (int i = begin; i < nums.size(); i++) {
			swap(nums[begin], nums[i]);
			permuteRecursive(nums, begin +  1, rslt);
			swap(nums[begin], nums[i]);
		}
	}

	void permuteDFS(vector<vector<int>> &rslt, vector<int>& nums, vector<int> &out, vector<int> &visited, int level) 
	{
		if (level >= nums.size()) {
			rslt.push_back(out);
		} else {
			for (int i = 0; i < nums.size(); ++i) {
				if (visited[i] == 0) {
					out.push_back(nums[i]);
					visited[i] = 1;
					
					permuteDFS(rslt, nums, out, visited, level + 1);
					
					visited[i] = 0;
					out.pop();
				}
			}
		}
	}
	
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input = {1, 2, 3};

	vector<vector<int>> target = {{1, 2, 3},
								  {1, 3, 2},
								  {2, 1, 3},
								  {2, 3, 1},
								  {3, 1, 2},
								  {3, 2, 1}};

	VERIFY_IS_EQUAL(sln.permute(input), target);
}