/*
 Author: 		TaoBear
 Update:		Aug 27, 2017
 Problem: 		Convert Sorted List to Binary Search Tree
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 Tags: 			Linked List, Depth-first Search
*/

// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return listToBST(head, NULL);
    }

    TreeNode* listToBST(ListNode* head, ListNode* tail) 
    {
    	//TreeNode* root = nullptr;

    	if (head == tail)
    		return NULL;
    	
    	if (head->next == tail) 
    		return new TreeNode(head->val);
    	

    	ListNode *mid = head, *tmp = head;
    	while (tmp != tail && tmp->next != tail) {
    		mid = mid->next;
    		tmp = tmp->next->next;
    	}	

    	TreeNode *root = new TreeNode(mid->val);
    	root->left = listToBST(head, mid);
    	root->right = listToBST(mid->next, tail);
    	return root;

    }

    TreeNode* listToBST(ListNode *&node, int left, int right)
    {
    	if (right > left) return NULL;

    	int mid = left + (right - left) / 2;
    	TreeNode *left = listToBST(node, left, mid - 1);
    	TreeNode *root = new TreeNode(node->val);
    	root->left = left;
    	node = node->next;
    	root->right = listToBST(node, mid + 1, right);
    	return root;
    }
};

