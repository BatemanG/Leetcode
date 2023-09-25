/**
  Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
**/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(), left, right, sum;

        if(n < 3) { return {}; }                                                // trivial case 1
        sort(nums.begin(), nums.end());                                         //O(NlogN)

        vector<vector<int>> result;
        for ( int i = 0; i < n-2; i++){
            if ( nums[i] > 0) {break;}                                          // as sum > 0 (as the array is sorted)
            if (i>0 && nums[i-1] == nums[i]) {continue;}                        // to skip duplicans we have already considered
            left = i+1;
            right = n-1;
            while ( left < right ) {
                sum = nums[i] + nums[left] + nums[right];
                if ( sum > 0) {right--; continue;}
                if ( sum < 0) {left++; continue;}
                result.push_back({nums[i],nums[left],nums[right]});
                while( left < right && nums[left] == nums[left + 1]) {left++;}          
                while( left < right && nums[right] == nums[right - 1]) {right--;}
                left++, right--;
            }
        }
        return result;
    }
};
