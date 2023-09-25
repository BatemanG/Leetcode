/**
Given an integer array arr, count how many elements x there are, such that x + 1 is also in arr. If there are duplicates in arr, count them separately.

Example 1:

Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
Example 2:

Input: arr = [1,1,3,3,5,5,7,7]
Output: 0
Explanation: No numbers are counted, cause there is no 2, 4, 6, or 8 in arr.
**/  

class Solution {
public:
    int countElements(vector<int>& arr) {
        
        int count = 0;
        unordered_map<int,int> dic;
        for (int i = 0; i < arr.size(); i++) {
            dic[arr[i]]++; 
        }
        
        for (auto [key, val]: dic) {
            if (dic.find(key + 1) != dic.end()) { count += val; }
        }
        return count;

    }
};
