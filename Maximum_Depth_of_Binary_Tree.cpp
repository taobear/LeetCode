/*
 Author: 		TaoBear
 Update:		Aug 27, 2017
 Problem: 		Maximum Depth of Binary Tree
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 Tags: 			Tree, Depthest first Search
*/

// Given a binary tree, find its maximum depth.

// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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

int maxDepthBFS(TreeNode* root) {
	if (root == NULL)
		return 0;

	int res = 0;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		++res;

		for (int i = 0; i < q.size(); ++i) {
			TreeNode* p = q.front();
			q.pop();

			if (p->left)
				q.push(p->left);
			else
				q.push(p->right);
		}
	}

	return res;
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

