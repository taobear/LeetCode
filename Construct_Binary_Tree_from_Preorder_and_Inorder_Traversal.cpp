/*
 Author: 		TaoBear
 Update:		Aug 27, 2017
 Problem: 		Construct Binary Tree from Preorder and Inorder Traversal
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 Tags: 			Tree, Array, Depthest first search
*/

// Given preorder and inorder traversal of a tree, construct the binary tree.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int prelen = preorder.size();
      int inlen = inorder.size();
      return buildTree(preorder, 0, prelen - 1, inorder, 0, inlen - 1);

    }

    TreeNode* buildTree(vector<int>& pre, int preStart, int preEnd, 
                        vector<int>& in, int inStart, int inEnd)
    {
        if (preStart > preEnd || inStart > inEnd)
          return NULL;

        int rootVal = pre[preStart];
        int rootIdx = 0;
        for (int i = inStart; i <= inEnd; ++i) {
          if (inorder[i] == rootVal)
            rootIdx = i;
        }

        TreeNode* root = new TreeNode(rootVal);
        int len = rootIdx - inStart;
        root->left = buildTree(pre, preStart + 1, preStart + len, in, inStart, rootIdx - 1);
        root->right = buildTree(pre, preStart + len + 1, preEnd, in, rootIdx + 1, inEnd);
        return root;
    }
};

