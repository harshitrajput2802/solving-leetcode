/*
Problem: 125. Valid Palindrome

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
    bool isPalindrome(string s) {
        int sz = s.size();
        int low = 0, high = sz - 1;
        while (low <= high) {
            char char_at_i = std::tolower(s[low]);
            char char_at_j = std::tolower(s[high]);

            if (!std::isalnum(char_at_i)) { // return true if there is aplhabet
                low++;
                continue;
            }
            if (!std::isalnum(char_at_j)) {
                high--;
                continue;
            }
            if (char_at_i != char_at_j)
                return false;

            low++;
            high--;
        }
        return true;
    }
};
/*
1. convert to lower case
2. agar alphabet nhi h to skip krna h
3. fir check krna h equal h ya nhi
*/