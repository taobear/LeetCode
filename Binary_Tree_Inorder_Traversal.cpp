/*
 Author: 		TaoBear
 Update:		Aug 26, 2017
 Problem: 		Binary Tree Inorder Traversal
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 Tags: 			Hash Table, Stack
*/

// Given a binary tree, return the inorder traversal of its nodes' values.

// For example:
// Given binary tree [1,null,2,3],
//    1
//     \
//      2
//     /
//    3
// return [1,3,2].

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

void inorderRecur(TreeNode* root, vector<int>& rslt) {
	if (!root) return;

	inorderRecur(root->left, rslt);
	rslt.push_back(root->val);
	inorderRecur(root->right, rslt);
}

vector<int> inorderIter(TreeNode* root) {
	stack<root*>  stk;
	vector<int>   rslt;

	while (root) {
		stk.push(root);
		root = root->left;
	}

	TreeNode *node;
	while (!stk.empty()) {
		node = stk.top();
		stk.pop();
		rslt.push_back(node->val);

		if (node->right) {
			node = node->right;
			while (node) {
				stk.push(node);
				node = node->left;
			}
		}
	}
	return rslt;
	
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
    }
};

int main(int argc, char **argv)
{
	
}