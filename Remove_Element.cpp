/*
 Author: 		TaoBear
 Update:		July 4, 2017
 Problem: 		Remove Element
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/remove-element/#/description
 Tags: 			Array, Two Pointers
*/

// Given an array and a value, remove all instances of that value in place and return the new length.

// Do not allocate extra space for another array, you must do this in place with constant memory.

// The order of elements can be changed. It doesn't matter what you leave beyond the new length.

// Example:
// Given input array nums = [3,2,2,3], val = 3

// Your function should return length = 2, with the first two elements of nums being 2.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len < 1) return 0;
        //if (len == 1 && nums[0] == val) return 0;

        int i = 0, j = len - 1;
        while (i <= j) {
        	if (nums[i] == val) 
        		nums[i] = nums[j--];
        	else
        		i++;
        }
        return i;
    }
};

int main(int argc, char **argv)
{

}