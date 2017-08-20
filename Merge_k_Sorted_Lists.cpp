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

// 注意 priority_queue<int> 维护的是最大堆
class Solution {
// typedef pair<int, ListNode*> Node;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	auto lam = [](const ListNode* lhs, const ListNode* rhs) {
    		return lhs->val > rhs->val;
    	};
 		priority_queue<ListNode*, vector<ListNode*>, decltype(lam)> min_heap(lam);
 		ListNode *head, *cur;
 		for (size_t i = 0; i < lists.size(); ++i) {
 			if (lists[i]) {
 				min_heap.push(lists[i]);
 			}
 		}
 		if (!min_heap.empty()) {
 			head = min_heap.top();
 			cur = head;
 			min_heap.pop();
 			if (cur->next) 
 				min_heap.push(cur->next);
 		}
 		// head = min_heap.top();
 		while (!min_heap.empty()) {
 			cur->next = min_heap.top();
 			cur = cur->next;
 			min_heap.pop();
 			if (cur->next) 
 				min_heap.push(cur->next);
 		}
		return head;
    }

};

int main(int argc, char **argv)
{

}