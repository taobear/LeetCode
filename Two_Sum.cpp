/*
 Author: 		TaoBear
 Update:		June 06, 2017
 Problem: 		Two Sum
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/two-sum/#/description
 Tags: 			Array, Hash Table
*/

// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:
// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include "leetcode.hpp"

class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {
     	unordered_map<int, int> nums_id;
     	int sz = static_cast<int>(nums.size());
     	for (int i = 0; i < sz; ++i)
     	{
     		int second = target - nums[i];

     		if (nums_id.find(second) != nums_id.end())
     			return vector<int>{nums_id[second], i};
     		else
     			nums_id[nums[i]] = i;

     	}
     	return vector<int>{};
    }

    vector<int> twoSum2(vector<int>& nums, int target) {
    	vector<pair<int, int>> pair_id(nums.size());
    	int n = nums.size();
    	for (int i = 0; i < n; ++i)
    	{
    		pair_id[i].first = nums[i];
    		pair_id[i].second = i;
    	}

    	auto lam = [](const pair<int, int>& lf, const pair<int, int>& rt) {
    		return lf.first < rt.first;
    	};
    	sort(pair_id.begin(), pair_id.end(), lam);

    	int l = 0, r = n - 1, sum = 0;
    	while (l < r)
    	{
    		sum = pair_id[l].first + pair_id[r].first;
    		if (sum < target)
    			l++;
    		else if (target < sum)
    			r--;
    		else
    			break;
    	}
		vector<int> ret;

    	if (l < r)
    	{
    		ret.push_back(min(pair_id[l].second, pair_id[r].second));
    		ret.push_back(max(pair_id[l].second, pair_id[r].second));
    	}	
    	
    	return ret;
    }
};


int main(int argc, char **argv)
{
	vector<int> nums = {2, 7, 11, 15};
	vector<int>	exp = {0, 1};
	int target = 9;

	Solution sln;
	VERIFY_IS_EQUAL(sln.twoSum2(nums, target), exp);

	VERIFY_REPORT();
}