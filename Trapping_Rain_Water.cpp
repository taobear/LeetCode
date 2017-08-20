/*
 Author: 		TaoBear
 Update:		July 22, 2017
 Problem: 		Trapping Rain Water
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/trapping-rain-water/#/description
 Tags: 			Array, Stack, Two Pointers
*/

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. 

#include "leetcode.hpp"

int trap1(vector<int>& height)
{
	int ans = 0;
	int size = height.size();

	for (int i = 0; i < size; ++i) {
		int max_left = 0, max_right = 0;
		for (int j = i; j >= 0; j--) {
			max_left = max(max_left, height[j]);
		}

		for (int j = i; j < size; j++) {
			max_right = max(max_right, height[j]);
		}

		ans += min(max_left, max_right) - height[i];
	}

	return ans;
}

int trap2(vector<int>& height)
{
	if (height.empty())
		return 0;

	int ans = 0;
	int size = height.size();

	vector<int> max_left(size), max_right(size);

	max_left[0] = height[0];
	max_right[size - 1] = height[size - 1];

	for (int i = 1; i < size; ++i) {
		max_left[i] = max(max_left[i - 1], height[i]);
	}

	for (int i = size - 2; i >= 0; --i) {
		max_right[i] = max(max_right[i + 1], height[i]);
	}

	for (int i = 1; i < size - 1; i++) {
		ans += min(max_left[i], max_right[i]) - height[i];
	}
	return ans;
}

int trap3(vector<int>& height)
{
	int left = 0, right = height.size() - 1;

	int ans = 0;
	int left_max = 0, right_max = 0;
	while (left < right) {
		if (height[left] < height[right]) {
			height[left] >= left_max ? left_max = height[left] : ans += left_max - height[left];
			left++;
		} else {
			height[right] >= right_max ? right_max = height[right] : ans += right_max - height[right];
			right--;
		}
	}

	return ans;
}

class Solution {
public:
	int trap(vector<int>& height) {
		return trap3(height);
	}

};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	VERIFY_IS_EQUAL(sln.trap(input1), 6);
}