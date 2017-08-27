/*
 Author: 		TaoBear
 Update:		Aug 27, 2017
 Problem: 		Validate Binary Search Tree
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/validate-binary-search-tree/description/
 Tags: 			Tree, Deepthest First Search
*/

// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// Example 1:
//     2
//    / \
//   1   3
// Binary tree [2,1,3], return true.
// Example 2:
//     1
//    / \
//   2   3
// Binary tree [1,2,3], return false.


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

int MinBST(TreeNode *root) {
	//int rslt = root->val;
	while (root->left) 
		root = root->left;
	return root->val;
}

void MaxBST(TreeNode *root) {
	while (root->right)
		root = root->right;
	return root->val;
}

// 采取中序遍历
bool isValidBSTRecur(TreeNode *root, TreeNode* minNode, TreeNode* maxNode) {
	if (!root) return true;

	if (minNode && root->val <= min->val || maxNode && root->val >= maxNode->val)
		return false;
	return isValidBSTRecur(root->left, minNode, root) && isValidBSTRecur(root->right, root, maxNode);
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
        	return true;
        
        if ((root->left && MaxBST(root->left) >= root->val) ||
        	!isValidBST(root->left))
        	return false;
        if ((root->right && root->val  >= MinBST(root->right)) ||
        	!isValidBST(root->right)) 
        	return false;
        return tree;
        	
    }
};

int main(int argc, char **argv)
{

}