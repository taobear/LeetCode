/*
 Author: 		TaoBear
 Update:		Aug 30, 2017
 Problem: 		Sum Root to Leaf Numbers
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 Tags: 			Tree, Deepthest First Search
*/

// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

// An example is the root-to-leaf path 1->2->3 which represents the number 123.

// Find the total sum of all root-to-leaf numbers.

// For example,

//     1
//    / \
//   2   3
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.

// Return the sum = 12 + 13 = 25.

#include "leetcode.hpp"

//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int sumNumbers(TreeNode* root) {
    	int sum = 0, up = 0;
    	dfsHelper(root, sum, up);
    	return sum;
    }

    void dfsHelper(TreeNode* root, int &sum, int up) {
    	if (!root) return;

    	int upNew = up * 10 + root->val;
    	if (!root->left && !root->right) {
    		sum += upNew;
    		return;
    	} 

    	if (root->left)
    		dfsHelper(root->left, sum, upNew);

    	if (root->right)
    		dfsHelper(root->right, sum, upNew);

    }
};

int main(int argc, char **argv)
{
	Solution sln;

	TreeNode *root = new TreeNode(0);
	TreeNode *node = new TreeNode(1);
	root->left = node;

	VERIFY_IS_EQUAL(sln.sumNumbers(root), 1);

	delete root;
	delete node;
}