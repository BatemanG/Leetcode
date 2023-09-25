/** 
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
**/

// Time: O(n) - Space: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, leftMax=0, rightMax=0, result = 0;
        while(left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            result += max(0, (leftMax < rightMax) ? leftMax - height[left++] : rightMax - height[right--] );  
        }
        return result;
    }
};
