/*
 Author: 		TaoBear
 Update:		Aug 20, 2017
 Problem: 		Jump Game II
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/jump-game-ii/description/
 Tags: 			Array, Greedy
*/


// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// For example:
// Given array A = [2,3,1,1,4]

// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

// Note:
// You can assume that you can always reach the last index.

#include "leetcode.hpp"

class Solution {
public:
	int jump(vector<int>& nums) {
        int size = nums.size();

        int step = 0, idx = 0;

        while (idx < size - 1) {
            int max_step = nums[idx];
            int max_val = 0;
            int max_idx = 0;
            for (int i = 1; i <= max_step; ++i) {
                if (idx + i >= size - 1) {
                    max_idx = idx + i;
                    break;
                }
                else if (idx + i + nums[idx + i] > max_val) {
                    max_idx = idx + i;
                    max_val = max_idx + nums[idx + i];
                }
            }

            idx = max_idx;
            step++;
        }

        return step;

	}
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> num = {2, 3, 1, 1, 4};
	int target = 2;

	VERIFY_IS_EQUAL(sln.jump(num), target);
}