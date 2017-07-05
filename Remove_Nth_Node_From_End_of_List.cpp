/*
 Author: 		TaoBear
 Update:		July 2, 2017
 Problem: 		Remove Nth Node From End of List
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/remove-nth-node-from-end-of-list/#/description
 Tags: 			Linked List, Two Pointers
*/

// Given a linked list, remove the nth node from the end of list and return its head.

// For example,

//    Given linked list: 1->2->3->4->5, and n = 2.

//    After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node1 = head, *node2 = head;

        int cnt = 0;
        while (cnt++ < n && node2) node2 = node2->next;
        if (cnt < n) return NULL;

        if (!node2) {
        	head = node1->next;
        	delete node1;
        	return head;
        }

        ListNode *prev = NULL;
        while (node2) {
        	prev = node1;
        	node1 = node1->next;
        	//next = node1->next;

        	node2 = node2->next;
        }

        prev->next = node1->next;
        delete node1;
        return head;
    }
};

