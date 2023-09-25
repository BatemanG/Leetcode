/**
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
**/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        counts[0] = 1;                                  //since the empty subarray has sum 0             
        int prefix = 0, ans = 0;

        for (int x: nums) {
            prefix += x;
            ans += counts[prefix - k];                  //since prefix - (prefix - k) = k 
            counts[prefix]++;
        }
        return ans;
    }
};
