/*
 Author: 		TaoBear
 Update:		Aug 27, 2017
 Problem: 		Path Sum
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/path-sum/description/
 Tags: 			Tree, Depth-first Search
*/


// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
       	return root->left || root->right ? (root->left && hasPathSum(root->left, sum - root->val))
       	 		                            || (root->right && hasPathSum(root->right, sum - root->val))
                                        : sum == root->val;
    }
};

