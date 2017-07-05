/*
 Author: 		TaoBear
 Update:		July 1, 2017
 Problem: 		3Sum
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/3sum/#/description
 Tags: 			Array, Two Pointers
*/

// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note: The solution set must not contain duplicate triplets.

// For example, given array S = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
#include "leetcode.hpp"

// Time Exceed
vector<vector<int>> threeSum1(vector<int>& nums) {
    size_t len = nums.size();
    if (len < 3) 
        return vector<vector<int>>();

    sort(nums.begin(), nums.end());
    vector<vector<int>> rst;
    int i = 0, j = len - 1, left = 0;
    for (int mid = 1; mid < len - 1; ++mid)
    {
        left = -nums[mid];
        i = 0, j = len - 1;
        while (i < mid && mid < j) {
            int sum = nums[i] + nums[j];
            if (sum < left) 
            {
               i++;
            }
            else if (sum > left)
            {
                j--;
            }
            else
            {
                vector<int> tmp{nums[i], nums[mid], nums[j]};
                auto iter = find(rst.begin(), rst.end(), tmp);
                if (iter == rst.end())
                    rst.push_back(tmp);
                i++;
            }
        }
    }
    return rst;
}

vector<vector<int>> threeSum2(vector<int>& nums) {
    size_t len = nums.size();
    if (len < 3)
        return vector<vector<int>>();

    sort(nums.begin(), nums.end());
    vector<vector<int>> rst;
    int left = 0, mid, right;
    int rem = 0, minVal = 0, maxVal = 0;
    for (; left < len - 2;) {
        rem = -nums[left];

        mid = left + 1;
        right = len - 1;

        minVal = nums[mid] + nums[mid + 1];
        maxVal = nums[right] + nums[right - 1];

        if (minVal <= rem && rem <= maxVal) 
        {

            while (mid < right) {
                if (nums[mid] + nums[right] < rem) {
                    mid++;
                }
                else if (nums[mid] + nums[right] > rem) {
                    right--;
                }
                else {
                    vector<int> tmp {nums[left], nums[mid], nums[right]};
                    rst.push_back(tmp);

                    while (++mid < right && tmp[1] == nums[mid]);
                    while (mid < --right && tmp[2] == nums[right]);
                }
            }
        }
        while (++left < len - 2 && nums[left] == -rem);
    }
    return rst;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    //return threeSum1(nums);
    return threeSum2(nums);
    }
};

int main(int argc, char **argv)
{
	vector<int> input1 = {-1, 0, 1, 2, -1, -4};
	Solution sln;
	vector<vector<int>> rst1 = {vector<int>{-1, 0, 1}, 
    vector<int>{-1, -1, 2}};

    VERIFY_IS_EQUAL(sln.threeSum(input1), rst1);
}