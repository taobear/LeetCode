/*
 Author: 		TaoBear
 Update:		Aug 25, 2017
 Problem: 		Remove Duplicates from Sorted List
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 Tags: 			Linked List
*/

// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

#include "leetcode.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* deleteDuplicates1(ListNode* head) {
	ListNode *list = head;

	while (list && list->next) {
		if (list->next->val == list->val) {
			list->next = list->next->next;
		} else {
			list = list->next;
		}
	}
	return head;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // ListNode *dummy = new ListNode(0);
        // dummy->next = head;

        ListNode *prev = head, *cur = head;
        while (cur) {
        	if (cur->val != prev->val) {
        		// prev->next = cur->next;
        		// prev = prev->next;
        		prev->next = cur;
        		prev = prev->next;
        	}
        	cur = cur->next;
        }
        if (prev)
        	prev->next = NULL;
        return head;
    }
};

int main(int argc, char **argv)
{

}