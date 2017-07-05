/*
 Author: 		TaoBear
 Update:		July 4, 2017
 Problem: 		Merge k Sorted Lists
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/merge-k-sorted-lists/#/description
 Tags: 			Divide and Conquer, Linked List, Heap
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
typedef pair<int, ListNode*> Node;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node> max_que(
        	[](const Node &lhs, const Node &rhs) {
        		return lhs.first < rhs.first;
        });

		for (auto l : lists)
			max_que.push(l);

		ListNode *head = max_que.pop().second();
		max_que.push(head->next);
		ListNode *prev = head;

		
    }

};

int main(int argc, char **argv)
{

}