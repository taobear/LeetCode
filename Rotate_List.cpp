/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
 Problem: 		Rotate List
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/rotate-list/description/
 Tags: 			Linked List, Two Pointer
*/


// Given a list, rotate the list to the right by k places, where k is non-negative.

// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "leetcode.hpp"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	if (!head) 
    		return head;

    	ListNode *tail = head;
    	int len = 1;
    	while (tail->next) {
    		tail = tail->next;
    	 	len++;
    	}

    	k %= len;
    	tail->next = head;
    	// 循环
    	k = len - k;
    	ListNode *cur = head;
    	while (k-- > 0) {
    		cur = cur->next;
    		tail = tail->next;
    	}
    	tail->next = NULL;
    	//head = cur;
    	return cur;
    }
};

int main(int argc, char **argv)
{

}