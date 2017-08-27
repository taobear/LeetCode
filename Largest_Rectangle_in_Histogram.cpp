/*
 Author: 		TaoBear
 Update:		Aug 25, 2017
 Problem: 		Largest Rectangle in Histogram
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 Tags: 			Array, Stack
*/

// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


// The largest rectangle is shown in the shaded area, which has area = 10 unit.

// For example,
// Given heights = [2,1,5,6,2,3],
// return 10.

#include "leetcode.hpp"

int largestRectangleArea1(vector<int> &heights) {
	int len = heights.size();
	int ans = 0;

	for (int i = 0; i < len; ++i) {
		int min_height = heights[i];

		for (int j = i + 1; j < len; ++j) {
			if (heights[j] < min_height) 
				min_height = heights[j];

			ans = max(ans, (j - i + 1) * min_height);
		}
	}

	return ans;
}

int largestRectangleArea2(vector<int> &heights) {
	int n = heights.size();
	if (n < 1) return 0;
	int maxArea = 0;

	stack<int> stk;
	stk.push(heights[0]);
	for (int i = 1; i < n; ++i) {
		if (stk.top() <= heights[i]) 
			stk.push(heights[i]);
		else {
			int cnt = 0;
			// int area = 0;
			int last = 0;
			while (!stk.empty() && stk.top() > heights[i]) {
				// last = stk.top();
				maxArea = max(maxArea, stk.top() * ++cnt);
				stk.pop();
			}

			// maxArea = max(maxArea, last * cnt);
			while (cnt-- >= 0) {
				stk.push(heights[i]);
			}
		}
	}

	//cout << stk.size() << endl;

	int num = 0;
	while (++num <= n) {
		maxArea = max(maxArea, stk.top() * num);
		stk.pop();
	}

	return maxArea;
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       // return largestRectangleArea1(heights);
    	return largestRectangleArea2(heights);
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {2, 1, 5, 6, 2, 3};
	vector<int> input2 = {3, 6, 5, 7, 4, 8, 1, 0};

	int target1 = 10;
	int target2 = 20;

	VERIFY_IS_EQUAL(sln.largestRectangleArea(input1), target1);
	VERIFY_IS_EQUAL(sln.largestRectangleArea(input2), target2);
}