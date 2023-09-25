/**
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
**/

// Time: O(n) Space: O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) {return 0;}

        sort(nums.begin(), nums.end()); //O(nlogn)
        int diffMinAbs = INT_MAX;
        int left, right, sum, result;
        
        for (int i = 0; i < n-2; i++){
            left = i+1;
            right = n-1;
            while( left < right ) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == target) { return sum; }
                if (sum < target ) { left++;} else {right--;}           
                if ( abs(sum - target) < diffMinAbs ) {
                    diffMinAbs = abs(sum - target);
                    result = sum;
                }   
            }
        }
        return result;
    }
};


// The logic we start with sorting the array then we have the pointers at
//  [i,left,...,right]
//  Now we work out the current sum, if its the target the return,
// not if it is less then the target the best we can do is to increase the sum,
// this is the same as moving the left (since the array is ordered) 
