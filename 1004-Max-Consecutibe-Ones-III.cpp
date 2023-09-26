/**
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
**/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // if the subarray is valid we make it bigger (right++)
        // if the subarray is not valid we keep it the same size but just move it acrros one (right++,left++)
        // We can do this since it is not asking where the largerst subarray is, but just the size of it
        // and thus the size (right - left) is not changed. 
        int left =0 , right;
        for(right = 0; right<nums.size(); right++){
            if (nums[right] == 0)   { k--; }
            if (k < 0)              { k += 1- nums[left++]; }
        }
        return right - left;
    }
};
