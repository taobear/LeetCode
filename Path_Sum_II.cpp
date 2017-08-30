/*
 Author: 		TaoBear
 Update:		Aug 29, 2017
 Problem: 		Path Sum II
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/path-sum-ii/description/
 Tags: 			Tree, Depth-first Search
*/

// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> rslt;
        vector<int> tmp;
        pathSumDFS(rslt, tmp, root, sum);
        return rslt;
    }

    void pathSumDFS(vector<vector<int>> &rslt, vector<int>& tmp, 
					TreeNode* root, int left) 
    {
    	// if (!root) return; 
    	// if (!root->left && !root->right) {
    	// 	if (left == root->val) {
    	// 		tmp.push_back(root->val);
    	// 		rslt.push_back(tmp);
    	// 		tmp.pop_back();
    	// 	}
    	// 	return;
    	// }
    	// tmp.push_back(root->val);
    	// pathSumDFS(rslt, tmp, root->left, left - root->val);
    	// pathSumDFS(rslt, tmp, root->right, left - root->val);
    	// tmp.pop_back();

    	if (!root) return;
    	tmp.push_back(root->val);
    	if (!root->left && !root->right && root->val == sum)
    		rslt.push_back(tmp);
    	pathSumDFS(rslt, tmp, root->left, left - root->val);
    	pathSumDFS(rslt, tmp, root->right, left - root->val);
    	tmp.pop_back();
    }
};

