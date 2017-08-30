/*
 Author: 		TaoBear
 Update:		Aug 27, 2017
 Problem: 		Minimum Depth of Binary Tree
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 Tags: 			Tree, Depth-first Search
*/


// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
    	if (!root) return 0;
        int minVal = INT_MAX;
        helper(root, 0, minVal);
        return minVal;
    }

    void helper(TreeNode* node, int level, int &minVal) {
    	if ((!node->left && !node->right) || level >= minVal) {
    		minVal = level < minVal ? level : minVal;
    	} else {
    		if (node->left)
    			helper(node->left, level + 1, minVal);
    		if (node->right)
    			helper(node->right, level + 1, minVal);
    	}
    }
};

