/*
 Author: 		TaoBear
 Update:		Aug 27, 2017
 Problem: 		Construct Binary Tree from Preorder and Inorder Traversal
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 Tags: 			Tree, Array, Depthest first search
*/

// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inlen = inorder.size();
        int postlen = postorder.size();
        return buildTree(inorder, 0, inlen - 1, postorder, 0, postlen - 1);
    }

    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, 
    					vector<int>& postorder, int postStart, int postEnd)
    {
    	if (inStart > inEnd || postStart > postEnd)
    		return NULL;

    	int rootVal = postorder[postEnd];
    	int rootIdx = inStart;
    	while (rootIdx <= inEnd && inorder[rootIdx] != rootVal)
    		rootIdx++;
    	TreeNode *root = new TreeNode(rootVal);
    	int len = rootIdx - inStart;
    	root->left = buildTree(inorder, inStart, rootIdx - 1,
    		                   postorder, postStart, postStart + len - 1);
    	root->right = buildTree(inorder, rootIdx + 1, inEnd, 
    							postorder, postStart + len, postEnd - 1);
    	return root;

    }
};

int main(int argc, char **argv)
{

}