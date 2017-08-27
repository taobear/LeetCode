/*
 Author: 		TaoBear
 Update:		Aug 27, 2017
 Problem: 		Same Tree
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/same-tree/description/
 Tags: 			Tree, Deepthest First Search
*/

// Given two binary trees, write a function to check if they are equal or not.

// Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) 
        	return !p && !q ? true : false;

        return p->val == q->val 
        		&& isSameTree(p->left, q->left) 
        		&& isSameTree(p->right, q->right);
    }	
};

