/**
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
**/



// // Times: O(n) & Space: O(n)

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size(), numZeros = 0;
//         vector<int> ans;

//         // Count the Zeros
//         for (int i=0; i < n;i++) { numZeros += (nums[i] == 0); }

//         // Add the non-Zeros
//         for (int i=0; i<n ; i++) { 
//             if ( nums[i] != 0 ) { ans.push_back(nums[i]); }
//         }

//         // Add the trailing Zeros
//         while (numZeros-- >= 0) { ans.push_back(0); }

//         // add the answer to nums 
//         for (int i=0; i<n; i++ ) { nums[i] = ans[i]; }
//     }
// };


// // Two pointer method //
// // Times: O(n) & Space: O(1)

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//       int n = nums.size(), lastNonZero = 0;
//       for (int i = 0; i < n; i++) {
//           if (nums[i] != 0) { nums[lastNonZero++] = nums[i]; }
//       }
//       for( int i = lastNonZero; i < n; i++) {
//           nums[i] = 0;
//       }
//     }
// };



// Times: O(n) & Space: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int lastNonZero = 0, current = 0; current < nums.size(); current++) {
            if (nums[current] != 0) { swap( nums[lastNonZero++], nums[current] ); }
        }
    }
};
