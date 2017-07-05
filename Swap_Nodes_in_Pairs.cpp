/*
 Author: 		TaoBear
 Update:		July 4, 2017
 Problem: 		Swap Nodes in Pairs
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/swap-nodes-in-pairs/#/description
 Tags: 			Linked List
*/

// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


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
    ListNode* swapPairs(ListNode* head) {
    	if (!head) return head;
        ListNode *dummyNode = new ListNode;
        dummyNode->next = head;

        ListNode *prev = dummyNode;
        ListNode *cur = head;
        ListNode *next = cur->next;

        while (next) {
        	prev->next = next;
        	cur->next = next->next;
        	next->next = cur;

        	if (cur->next) {
        		prev = cur;
        		cur = cur->next;
        		next = cur->next;
        	}
        	else
        		break;
        }
        return dummyNode->next;
    }
};

