/*
 Author: 		TaoBear
 Update:		Aug 26, 2017
 Problem: 		Largest Rectangle in Histogram
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 Tags: 			Array, Stack
*/

// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *less = dummy;
        ListNode *prev = dummy;

        while (prev->next) {
            if (prev->next->val < x) {
                if (prev == less) {
                    prev = prev->next;
                    less = less->next;
                } else {
        		  ListNode *cur = prev->next;
        		  prev->next = prev->next->next;
        		  cur->next = less->next;
        		  less->next = cur;
        		  less = less->next;
        	} else { 
        		prev = prev->next;
        	}
        }
        return dummy->next;
    }
};

int main(int argc, char **argv)
{

}