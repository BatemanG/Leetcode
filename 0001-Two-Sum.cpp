/**
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
**/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int num, complement;
        unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++) {
            num = nums[i];
            complement = target - num;
            // if (dic.find(complement) != dic.end()) { return {i, dic[complement]}; }  
            // note that we could use count instead of find != ... since 1,2,3,.. all would be 'true'
            if (dic.count(complement)) { return {i, dic[complement]}; }
            dic[num] = i;
        }
        return {-1,-1};
    }   
};
