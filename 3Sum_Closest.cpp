/*
 Author: 		TaoBear
 Update:		July 1, 2017
 Problem: 		3Sum Closest
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/3sum-closest/#/description
 Tags: 			Array, Two Pointers
*/


// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 

// Return the sum of the three integers. You may assume that each input would have exactly one solution.

// For example, given array S = {-1 2 1 -4}, and target = 1.

// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include "leetcode.hpp"
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	size_t len = nums.size();
    	if (len < 3) return 0;
        
        sort(nums.begin(), nums.end());
        int left = 0, mid = 0, right = 0;
        int res = 0, result = nums[0] + nums[1] + nums[2];
        while (left < len - 2) {
        	res = target - nums[left];
        	int left_val = nums[left];

        	mid = left + 1;
        	right = len - 1;
        	while (mid < right) {
        		int sum = nums[mid] + nums[right];
        		int mid_val = nums[mid], right_val = nums[right];

        		result = abs(result - target) > abs(sum + nums[left] - target) 
        			? sum + nums[left] : result;

        		if (sum < res) {
        			mid++;
        		}
        		else if (sum > res){
        			right--;
        		}
        		else 
        			return target;
        		
        	}
        	while (++left < len - 2 && nums[left] == left_val);
        }
        return result;
    }	
};

int main(int argc, char **argv)
{
	vector<int> input1 = { -1, 2, 1, -4};
	vector<int> input2 = { 1, 1, 1, 0};
	vector<int> input3 = { 0, 2, 1, -3};
	vector<int> input4 = {1, 2, 4, 8, 16, 32, 64, 128};
	Solution sln;

	int rslt1 = sln.threeSumClosest(input1, 1);
	int rslt2 = sln.threeSumClosest(input2, 100);
	int rslt3 = sln.threeSumClosest(input3, 1);
	int rslt4 = sln.threeSumClosest(input4, 82);

	VERIFY_IS_EQUAL(rslt1, 2);
	VERIFY_IS_EQUAL(rslt2, 3);
	VERIFY_IS_EQUAL(rslt3, 0);
	VERIFY_IS_EQUAL(rslt4, 82);
}
