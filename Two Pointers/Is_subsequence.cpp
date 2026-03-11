/*
Problem: 392. Is subsequence

Problem Description:
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string 
by deleting some (can be none) of the characters without disturbing the relative positions 
of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
s and t consist only of lowercase English letters so no need for case conversion.

Our Approach:
- Use two pointers: one at "t", say 'i' and one at "s", say 'j'
- 'j' tracks the character to be searched and 'i' iterates on "t" to find it
- if the character at both i and j are same then move ahead in "s"
- move in "t" in either ways
- if we have reached beyond the end of "s" which means it is a subsequence

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        // 'i' iterates through t, 'j' tracks position in s
        while (i < t.size()) {
            if (t[i] == s[j])
                j++;
            i++;
        }
        return j >= s.size();
    }
};