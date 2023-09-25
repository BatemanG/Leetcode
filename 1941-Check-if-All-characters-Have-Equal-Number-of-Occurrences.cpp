/**
Given a string s, return true if s is a good string, or false otherwise.

A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

Example 1:

Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
Example 2:

Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
**/

// Time O(n), Space O(n) 

// Important note: sets dont allow for duplicants

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> counts;
        for (char c: s) {
            counts[c]++;
        }

        unordered_set<int> freq;
        for (auto [key,val]: counts){
            freq.insert(val); 
        }

        return freq.size() == 1;
    }
};
