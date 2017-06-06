/*
 Author: 		TaoBear
 Update:		June 06, 2017
 Problem: 		Add Two Numbers
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/add-two-numbers/#/description
 Tags: 			Linked List, Math
*/


// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(0);

        if (!l1 && !l2) return dummyHead;

        ListNode *cur = dummyHead;
        int sum = 0, carry = 0;

        while (l1 || l2)
        {
        	int num1 = l1 == NULL ? 0 : l1->val;
        	int num2 = l2 == NULL ? 0 : l2->val;

        	sum = num1 + num2 + carry;

        	cur->next = new ListNode(sum % 10);
        	carry = sum / 10;

        	if (l1) l1 = l1->next;
        	if (l2) l2 = l2->next;
        	cur = cur->next;
        }

        if (carry) cur->next = next = new ListNode(array);
        return dummyHead->next;
    }
};