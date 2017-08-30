/*
 Author: 		TaoBear
 Update:		Aug 27, 2017
 Problem: 		Balanced Binary Tree
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/balanced-binary-tree/description/
 Tags: 			Tree, Depth-first Search
*/

// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int left = height(root->left);
        int right = height(root->right);
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode *root) {
    	if (!root) return 0;
    	return max(height(root->left), height(root->right)) + 1;
    }
};

