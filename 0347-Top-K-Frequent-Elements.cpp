/**
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
**/

// method 1
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        //O(1)
        if (k == n) { return nums; }
        //O(n)
        unordered_map<int,int> counts;
        for (int x: nums) {
            counts[x]++;
        }
        
        auto comp = [&counts](int n1, int n2) { return counts[n1] > counts[n2]; };

        priority_queue<int, vector<int>, decltype(comp)> heap(comp);

        for (auto [key,val]: counts) {
            heap.push(key);
            if (heap.size() > k) { heap.pop(); }
        }

        vector<int> result;

        for (int i = 0; i < k; i++){
            result.push_back(heap.top());
            heap.pop();
        }
        return result;
    }
};



// method 2
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        //O(1)
        if (k == n) { return nums; }
        //O(n)
        unordered_map<int,int> counts;
        for (int x: nums) {
            counts[x]++;
        }
        //0(n)
        vector<vector<int>> buckets(n + 1, vector<int>()); 
        for (auto [key,val]: counts) {
            buckets[val].push_back(key);
        }
        //O(n) 
        vector<int> result;
        for (int i = n; i >= 0; i--) { 
            if (result.size() >= k) { break;   } 
            if (buckets[i].empty())    {continue; }

            result.insert(result.end(), buckets[i].begin(), buckets[i].end());
        }

        return result;
    }
};
