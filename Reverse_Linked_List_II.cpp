/*
 Author: 		TaoBear
 Update:		Aug 26, 2017
 Problem: 		Reverse Linked List II
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/reverse-linked-list-ii/description/
 Tags: 			Linked List
*/

// Reverse a linked list from position m to n. Do it in-place and in one-pass.

// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,

// return 1->4->3->2->5->NULL.

// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = findKthNode(dummy, m - 1),
        		 *tail = findKthNode(dummy, n);

        while (prev->next != tail) {
        	ListNode *tmp = prev->next;
        	prev->next = tmp->next;
        	tmp->next = tail->next;
        	tail->next = tmp;
        }
        return dummy->next;
    }

    ListNode* findKthNode(ListNode *head, int kth) {
    	ListNode *res = head;
    	while (res && kth--) 
    		res = res->next;
    	return res;
    }
};

int main(int argc, char **argv)
{

}