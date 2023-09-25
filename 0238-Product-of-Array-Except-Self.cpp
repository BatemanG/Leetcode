/**
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
**/



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = count(nums.begin(),nums.end(), 0);
        if (zeroCount > 1) {
            return vector<int>(nums.size(), 0);
        }

        int product = accumulate(nums.begin(), nums.end(), 1,
                     [](int a, int b){return (b == 0) ? a : a * b;} );

        vector<int> answer;
        for (int num: nums) {
            if (zeroCount == 1){ answer.push_back((num == 0) ? product: 0);}
            else { answer.push_back(product/num); }
            
        }
        return answer;
    }
};
