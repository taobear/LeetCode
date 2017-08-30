/*
 Author: 		TaoBear
 Update:		Aug 27, 2017
 Problem: 		Binary Tree Level Order Traversal II
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 Tags: 			Tree, Breadthest first search
*/

// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	vector<vector<int>> rslt;
        if (root)
        	bfsHelper(rslt, root, 0);
        reverse(rslt.begin(), rslt.end());
        return rslt;
    }

    void bfsHelper(vector<vector<int>> &rslt, TreeNode* root, int level) {
    	if (level == rslt.size())
    		rslt.push_back(vector<vector<int>>{});

    	rslt[level].push_back(root->val);

    	if (root->left)
    		bfsHelper(rslt, root->left, level + 1);
    	if (root->right)
    		bfsHelper(rslt, root->right, level + 1);
    }
};