/*
 Author: 		TaoBear
 Update:		Aug 27, 2017
 Problem: 		Binary Tree Level Order Traversal II
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 Tags: 			Tree, Breadthest first search
*/


// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
#include "leetcode.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "leetcode.hpp"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
    	if (left > right)
    		return NULL;
    	int mid = left + (right - left) / 2;
    	TreeNode *node = new TreeNode(nums[mid]);

    	node->left = sortedArrayToBST(nums, left, mid - 1);
    	node->right = sortedArrayToBST(nums, mid + 1, right);
    	return node;
    }
};