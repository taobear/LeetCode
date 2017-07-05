/*
 Author: 		TaoBear
 Update:		June 16, 2017
 Problem: 		Container With Most Water
 Difficulty: 	Median
 Source:		https://leetcode.com/problems/container-with-most-water/#/description
 Tags: 			Array, Two Pointer
*/

// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the 
// two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains
// the most water.

// Note: You may not slant the container and n is at least 2.

// 反证法： 在j的右边不会有一条线比它高
//          在i的左边不会有一条线比它高

// 当左端线段L小于右端线段时，我们把L右移，这是舍弃的是L与右端其他线段（R-1, R-2, R-3,...) 组成的木桶
// 这些木桶是没必要比较判断的，因为木桶的容积没有L和R组成的木桶容积大

// 直观的解释是：容积即面积，它受长和高的影响，当长度减小时候，高必须增长才有可能提升面积，
// 所以我们从长度最长时开始递减，然后寻找更高的线来更新候补；

#include "leetcode.hpp"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i = 0, j = len - 1;
        int rslt = 0;

        if (len == 0) return 0;
        while (i < j) {
        	//rslt = max(rslt, height[i] * (j - i)); 
			if (height[i] < height[j])
            {
                rslt = max(rslt, height[i] * (j - i));
        		i++;
            }
        	else
            {
                rslt = max(rslt, height[j] * (j - i));
        		j--;
            }
        }
        return rslt;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 {1, 1};

	int result1 = sln.maxArea(input1);

	VERIFY_IS_EQUAL(result1, 1);

	VERIFY_REPORT();
}