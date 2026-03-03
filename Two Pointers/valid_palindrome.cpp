/*
Problem: 344. Reverse String

Problem Description:
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
and removing all non-alphanumeric characters, it reads the same forward and backward.
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Our Approach:
- Use two pointers: 'i' at the start and 'j' at the end
- Convert both characters to lowercase to ensure case-insensitivity
- Skip non-alphanumeric characters using std::isalnum()
- Compare characters; if they don't match, it's not a palindrome
- If the pointers meet then it is palindrome

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int sz = s.size();
        int i = 0, j = sz - 1;
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
};