/*
 Author: 		TaoBear
 Update:		Aug 26, 2017
 Problem: 		Unique Binary Search Trees II
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 Tags: 			Tree, Dynamic Programming
*/

// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

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

// Dynamic Programming
TreeNode* CopyOffSet(TreeNode *root, int off) {
	if (!root) return root;
	TreeNode *node = new TreeNode(root->val);
	node->val -= off;
	node->left = OffSet(root->left, off);
	node->right = OffSet(root->right, off);
	return node;
}

vector<TreeNode*> geneDynamic(int n) {
	// vector<TreeNode*> dp
	vector<vector<TreeNode *> 
}

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1)
        	return vector<TreeNode *>{};
        return helper(1, n);
    }

    vector<TreeNode*> helper(int start, int end) {
    	vector<TreeNode*> res;

    	if (start > end) {
    		res.push(NULL);
    		return res;
    	}

    	for (int i = start; i <= end; ++i) {
    		vector<TreeNode*> left = helper(start, i - 1);
    		vector<TreeNode*> right = helper(i + 1, end);

    		for (auto & l : left) {
    			for (auto & r : right) {
    				ListNode *root = new ListNode(i);
    				root->left = l;
    				root->right = r;
    				res.push_back(root);
    			}
    		}

    	}

    	return res;
	}
};

int main(int argc, char **argv)
{
	Solution sln;

	
}