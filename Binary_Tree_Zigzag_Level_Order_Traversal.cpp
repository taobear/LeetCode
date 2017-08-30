/*
 Author: 		TaoBear
 Update:		Aug 27, 2017
 Problem: 		Binary Tree Zigzag Level Order Traversal
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 Tags: 			Tree, Breadth First Search, Stack
*/

// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int flag = true;
        vector<vector<int>> rslt;
        zigzagLevelOrderBFS(rslt, root, 0);
        for (int i = 0; i < rslt.size(); ++i) {
        	if (i % 2)
        		reverse(rslt[i].begin(), rslt[i].end());
        }
        return rslt;
    }

    void zigzagLevelOrderBFS(vector<vector<int>>& rslt, TreeNode* root, int level) 
    {
    	if (!root)
    		return;
    	if (rslt.size() <= level)
    		rslt.push_back(vector<int>{});

    	rslt[level].push_back(root->val);
    	zigzagLevelOrderBFS(rslt, root->left, level + 1);
    	zigzagLevelOrderBFS(rslt, root->right, level + 1);
    }
};

int main(int argc, char **argv)
{

}