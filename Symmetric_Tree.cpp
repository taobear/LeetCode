/*
 Author: 		TaoBear
 Update:		Aug 27, 2017
 Problem: 		Same Tree
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/same-tree/description/
 Tags: 			Tree, Deepthest First Search
*/

// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.

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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return !root || isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* left, TreeNode* right) {
    	if (!left || !right)
    		return left == right;

    	return left->val == right->val
    		   && isSymmetric(left->left, right->right)
    		   && isSymmetric(left->right, right->left);
    }
};

