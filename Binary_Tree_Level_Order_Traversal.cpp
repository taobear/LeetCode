/*
 Author: 		TaoBear
 Update:		Aug 27, 2017
 Problem: 		Binary Tree Level Order Traversal
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 Tags: 			Tree, Breadth First Search
*/

// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> rslt;

        if (root)
        	q.push(root);
        while (!q.empty()) {
        	Queue<TreeNode*> tmp;
        	vector<int> vec;
        	while (!q.empty()) {
        		TreeNode* v = q.front();
        		q.pop();
        		vec.push_back(v->val);
        		if (v->left) tmp.push(v->left);
        		if (v->right) tmp.push(v->right);
       		}
       		rslt.push_back(vec);
       		q = tmp;
        }
        return rslt;
    }
    void buildVector(vector<vector<int>> & rslt, TreeNode* root, int depth) {
    	if (!root) return;
    	if (rslt.size() == depth)
    		rslt.push_back(vector<int>{});

    	rslt[depth].push_back(root->val);
    	buildVector(rslt, root->left, depth + 1);
    	buildVector(rslt, root->right, depth + 1);
    }

};

int main(int argc, char **argv)
{

}