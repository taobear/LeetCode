/*
 Author: 		TaoBear
 Update:		July 2, 2017
 Problem: 		Merge Two Sorted Lists
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/merge-two-sorted-lists/#/description
 Tags: 			Linked List
*/

// Merge two sorted linked lists and return it as a new list.
// The new list should be made by splicing together the nodes of the first two lists.

#include "leetcode.hpp"

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if (!l1 || !l2) 
    		return l1 ? l1 : l2;
 		ListNode *head, *cur1, *cur2;
 		if (l1->val < l2->val) {
 			head = l1;
 			cur1 = l1->next;
 		}
 		else {
 			head = l2;
 			cur2 = l2->next;
 		}
 		ListNode *prev = head;
 		// ListNode *next = NULL;

 		while (cur1 && cur2) {
 			if (cur1->val < cur2->val) {
 				prev->next = cur1;
 				cur1 = cur1->next;
 			}
 			else {
 				prev->next = cur2;
 				cur2 = cur2->next;
 			}

 			prev = prev->next;
 		}
 		prev->next = cur1 ? cur1 : cur2;
 		return head;
    }
};

int main(int argc, char **argv)
{

}