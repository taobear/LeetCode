/*
 Author: 		TaoBear
 Update:		June 10, 2017
 Problem: 		Median of Two Sorted Arrays
 Difficulty: 	hard
 Source:		https://leetcode.com/problems/median-of-two-sorted-arrays/#/description
 Tags: 			Binary Search, Array, Divide and Conquer
*/


// There are two sorted arrays nums1 and nums2 of size m and n respectively.

// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

// Example 1:
// nums1 = [1, 3]
// nums2 = [2]

// The median is 2.0
// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]

// The median is (2 + 3)/2 = 2.5

#include "leetcode.hpp"

double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> num;
	int n1 = nums1.size(), n2 = nums2.size();
	int i = 0, j = 0;
	while (i < n1 && j < n2)
	{
		if (nums1[i] < nums2[j])
		{
			num.push_back(nums1[i]);
			i++;
		}
		else 
		{
			num.push_back(nums2[j]);
			j++;
		}
	}

	for (; i < n1; ++i)
		num.push_back(nums1[i]);
	for (; j < n2; ++j)
		num.push_back(nums2[j]);

	int mid = (n1 + n2) / 2;

	if ((n1 + n2) % 2)
		return num[mid];
	else
		return (num[mid - 1] + num[mid]) / 2.;
}

int findKth1(vector<int>& nums1, vector<int>& nums2, int k)
{
	int p = 0, q = 0;
	int m = nums1.size();
	int	n = nums2.size(); 

	for (int i = 0; i < k - 1; ++i) {
		if (p >= m)
			q++;
		else if (q >= n)
			p++;
		else if (nums1[p] < nums2[q])
			p++;
		else
			q++;
	}

	if (p >= m)
		return nums2[q];
	else if (q >= n)
		return nums1[p];
	else
		return min(nums1[p], nums2[q]);
}

// conclusion:
// Assume that the number of elements in A and B are both larger than k/2,
// and if we compare the k/2-th smallest element in A(i.e. A[k/2-1]) and the k-th smallest element in B(i.e. B[k/2 - 1]), there are three results:
// (Becasue k can be odd or even number, so we assume k is even number here for simplicy. The following is also true when k is an odd number.)
// A[k/2-1] = B[k/2-1]
// A[k/2-1] > B[k/2-1]
// A[k/2-1] < B[k/2-1]
// if A[k/2-1] < B[k/2-1], that means all the elements from A[0] to A[k/2-1](i.e. the k/2 smallest elements in A) are in the range of k smallest elements in the union of A and B.
// Or, in the other word, A[k/2 - 1] can never be larger than the k-th smalleset element in the union of A and B.

// proof: 
// Since A[k/2 - 1] is larger than the k-th smallest element in the union of A and B, then we assume it is the (k+1)-th smallest one.
// Since it is smaller than B[k/2 - 1], then B[k/2 - 1] should be at least the (k+2)-th smallest one. 
// So there are at most (k/2-1) elements smaller than A[k/2-1] in A, and at most (k/2 - 1) elements smaller than A[k/2-1] in B.
// So the total number is k/2+k/2-2, which, no matter when k is odd or even, is surly smaller than k(since A[k/2-1] is the (k+1)-th smallest element).
// So A[k/2-1] can never larger than the k-th smallest element in the union of A and B if A[k/2-1]<B[k/2-1];

int findKth2(vector<int>& nums1, int beg1, int end1, vector<int>& nums2, int beg2, int end2, int k)
{
	int n1 = end1 - beg1;
	int n2 = end2 - beg2;

 	if (n1 > n2)
		return findKth2(nums2, beg2, end2, nums1, beg1, end1, k);
	if (n1 == 0)
		return nums2[beg2 + k - 1];
	if (k == 1)
		return min(nums1[beg1], nums2[beg2]);

	int pa = min(k / 2, n1), pb = k - pa;

	if (nums1[pa - 1 + beg1] < nums2[pb - 1 + beg2])
		return findKth2(nums1, pa + beg1, end1, nums2, beg2, end2, k - pa);
	else if (nums1[pa - 1 + beg1] > nums2[pb - 1 + beg2])
		return findKth2(nums1, pa, end1, nums2, pb + beg2, end2, k - pb);
	else
		return nums1[pa - 1 + beg1];
}

int findKth(vector<int>& nums1, vector<int>& nums2, int k)
{
	//return findKth1(nums1, nums2, k);
	return findKth2(nums1, 0, nums1.size(), nums2, 0, nums2.size(), k);
}

double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size();
	int n = nums2.size();

	int mid = (m + n) / 2;

	if ((m + n) % 2)
		return findKth(nums1, nums2, mid + 1);
	else
		return (findKth(nums1, nums2, mid) + findKth(nums1, nums2, mid + 1)) / 2.;

}



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //return findMedianSortedArrays1(nums1, nums2);
        return findMedianSortedArrays2(nums1, nums2);
    }
};

int main(int argc, char **argv)
{
	vector<int> test1_num1 = {1, 3}, test1_num2 = {2};
	vector<int> test2_num1 = {1, 2}, test2_num2 = {3, 4};

	Solution sln;

	double rst1 = sln.findMedianSortedArrays(test1_num1, test1_num2);
	double rst2 = sln.findMedianSortedArrays(test2_num1, test2_num2);

	VERIFY_IS_EQUAL(rst1, 2.0);
	VERIFY_IS_EQUAL(rst2, 2.5);

	VERIFY_REPORT();
}