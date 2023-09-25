/**
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
**/


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // O(k log k)
        priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);

        //  O(n - k)
        for (int i = k; i < nums.size(); i++) {
            // O(1)
            if(nums[i] > min_heap.top()) {
                // Removing the smallest number from the heap: O(log k)
                min_heap.pop();
                // Inserting a number into the heap: O(log k)
                min_heap.push(nums[i]);
            }
        }
        // Returning the top of the heap: O(1)
        return min_heap.top();
    }
};
