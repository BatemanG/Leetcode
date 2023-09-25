/**
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"
**/

// // Time: O(N) - Space: O(1)
// class Solution {
// public:
//     string reverseWords(string s) {
//         string results;
//         int startOfWord = -1, n = s.length(), endOfWord;

//         for (int currentIndex= 0; currentIndex < n; currentIndex++) {
//             // if found end of word start the switch
//             if (currentIndex == n - 1 || s[currentIndex] == ' ') {
//                 endOfWord = (currentIndex == n - 1) ? currentIndex : currentIndex - 1;
//                 // reverse current word      
//                 while ( endOfWord > startOfWord) { results += s[endOfWord--];    }
//                 // if not the end add a space, to start next word
//                 if (currentIndex != n - 1) { results += ' ';}
//                 startOfWord = currentIndex;
//             }
//         }
//         return results;
//     } 
// };


// Two Pointer method
class Solution {
public:
    string reverseWords(string s) {
        int lastSpaceIndex = -1, n = s.length(), endOfWord, startOfWord;
        for (int currentIndex = 0; currentIndex < n; currentIndex++) {
            if (currentIndex == n - 1 || s[currentIndex] == ' ') {
                startOfWord = lastSpaceIndex + 1;
                endOfWord = (currentIndex == n - 1) ? currentIndex : currentIndex - 1;
                while (startOfWord < endOfWord) { swap(s[startOfWord++], s[endOfWord--]); }
                lastSpaceIndex = currentIndex;
            }
        }
        return s;
    } 
};
