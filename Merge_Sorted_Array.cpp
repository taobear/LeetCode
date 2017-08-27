/*
 Author: 		TaoBear
 Update:		Aug 26, 2017
 Problem: 		Merge Sorted Array
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/merge-sorted-array/description/
 Tags: 			Array, Two Pointer
*/


// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// Note:
// You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional
// elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

#include "leetcode.hpp"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sum = m + n;
        int p1 = m - 1, p2 = n - 1, pn = sum - 1;

        while (p2 >= 0) {
        	if (p1 >= 0 && nums1[p1] > nums2[p2])
        		nums1[pn] = nums1[p1--];
        	else
        		nums1[pn] = nums2[p2--];
        	pn--;
        }

    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> nums1 = {1, 2, 5, 7, 0, 0, 0};
	vector<int> nums2 = {4, 5, 6};


	vector<int> nums21 = {0, 0, 3, 0, 0, 0, 0, 0, 0};
	vector<int> nums22 = {-1, 1, 1, 1, 2, 3};

	vector<int> target1 = {1, 2, 4, 5, 5, 6, 7};
	vector<int> target2 = {-1, 0, 0, 1, 1, 1, 2, 3, 3};

	sln.merge(nums1, 4, nums2, 3);
	sln.merge(nums21, 3, nums22, 6);

	VERIFY_IS_EQUAL(nums1, target1);
	VERIFY_IS_EQUAL(nums21, target2);
}