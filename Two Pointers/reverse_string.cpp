/*
Problem: 344. Reverse String

Problem Description:
Write a function that reverses a string. The input string is given as an array of characters s.
Apply in-place algorithm.

Our Approach:
- Use two pointers: 'i' at the start and 'j' at the end 
- Swap the characters at these two positions.
- Move 'i' forward and 'j' backward.
- Continue until they meet at the middle

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