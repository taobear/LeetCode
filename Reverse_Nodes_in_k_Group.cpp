/*
 Author: 		TaoBear
 Update:		July 4, 2017
 Problem: 		Reverse Nodes in k-Group
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/reverse-nodes-in-k-group/#/description
 Tags: 			Linked List
*/

// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list.

// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// You may not alter the values in the nodes, only nodes itself may be changed.

// Only constant memory is allowed.

// For example,
// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "leetcode.hpp"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	ListNode *last = head;
    	int 	  cnt = 0;

    	for ( ; cnt < k && last; ++cnt) 
    		last = last->next;

    	if (cnt < k || k < 2) 
    		return head;
   
    	// Reverse
    	ListNode *dummy = new ListNode(-1);
    	dummy->next = head;
    	ListNode *prev = dummy->next,
    			 *cur = prev->next;

    	while (cur != last) {
    		prev->next = cur->next;
    		cur->next = dummy->next;
    		dummy->next = cur;
    		cur = prev->next;
    	}

    	head = dummy->next;

    	delete dummy;
    	prev->next = reverseKGroup(last, k);
    	return head;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	n1->next = n2;

	ListNode *head = sln.reverseKGroup(n1, 2);
	while (head) {
		cout << head->val;
		head = head->next;
	}
}