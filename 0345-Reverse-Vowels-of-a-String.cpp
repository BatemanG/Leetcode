/**
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 
**/

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u', 'A','E','I','O','U'};
        int left = 0, right = s.size();
        while ( left < right ) {
            if (vowels.count(s[left]) && vowels.count(s[right]) ) {
                swap(s[left++], s[right--]);
            } else if (vowels.find(s[left]) == vowels.end()) { left++; }
            else if (vowels.find(s[right]) == vowels.end() ) {right--;}
        }
        return s;
    }
};
