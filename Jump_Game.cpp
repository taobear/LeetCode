/*
 Author: 		TaoBear
 Update:		Aug 21, 2017
 Problem: 		Jump Game
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/jump-game/description/
 Tags: 			Array, Greedy
*/

// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

// For example:
// A = [2,3,1,1,4], return true.

// A = [3,2,1,0,4], return false.

#include "leetcode.hpp"

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int size = nums.size();

        int idx = 0;

        while (idx < size - 1 && nums[idx]) {
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
            //step++;
        }

        return idx < size - 1 ? false : true;
	}
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {2, 3, 1, 1, 4};
	vector<int> input2 = {3, 2, 1, 0, 4};

	bool target1 = true;
	bool target2 = false;

	VERIFY_IS_EQUAL(sln.canJump(input1), target1);
	VERIFY_IS_EQUAL(sln.canJump(input2), target2);

}