/*
 Author: 		TaoBear
 Update:		Aug 29, 2017
 Problem: 		Populating Next Right Pointers in Each Node II
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 Tags: 			Tree, Depth-first Search
*/

// Follow up for problem "Populating Next Right Pointers in Each Node".

// What if the given tree could be any binary tree? Would your previous solution still work?

// Note:

// You may only use constant extra space.
// For example,
// Given the following binary tree,
//          1
//        /  \
//       2    3
//      / \    \
//     4   5    7
// After calling your function, the tree should look like:
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \    \
//     4-> 5 -> 7 -> NULL

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

void connect1(TreeLinkNode *root) 
{
	while (root) {
		TreeLinkNode *head = NULL, *prev = NULL;

		while (root) {
			if (root->left) {
				if (prev) {
					prev->next = root->left;
				} else {
					head = root->left;
				}
				prev = root->left;
			}

			if (root->right) {
				if (prev) {
					prev->next = root->right;
				} else {
					head = root->right;
				}
				prev = root->right;
			}
			root = root->next;
		}

		root = head;
	}
}

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;

        while (root) 
        {
        	TreeLinkNode *head = NULL, *prev = NULL;	

        	while (root) 
        	{
        		if (root->left) {
        			if (!head) {
        				head = root->left;
        				prev = head;
        			}
        			else {
        				prev->next = root->left;
        				prev = prev->next;
        			}
        		}
        		if (root->right) {
        			if (!head) {
        				head = root->right;
        				prev = head;
        			} 
        			else {
        				prev->next = root->right;
        				prev = prev->next;
        			}
        		}
        		root = root->next;
        	}
        	root = head;
        }
    }
};