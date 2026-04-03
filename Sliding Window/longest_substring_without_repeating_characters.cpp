/*
Problem: 3. Longest Substring Without Repeating Characters

Problem Description:
Given a string s, find the length of the longest substring without duplicate characters.

Our Approach(Variable Size Sliding Window + Hashing):
- We use two pointers (l, r) to maintain a window and an unordered_map to store frequency of characters
- Expand the window by moving r and include s[r] in the map
- If a duplicate character is found (frequency > 1), shrink the window from the left (l++)
    until the window becomes valid again (no duplicates)
- At every valid window, calculate its length (r - l + 1) and update the maximum window lenght'maxLen'
- Continue this process until r reaches the end of the string

Time Complexity: O(n)
Space Complexity: O(1)

- Why Space Complexity is not O(n)?
       The hashmap stores characters, not indices or substrings and maximum possible distinct characters is limited(max 256).
       So, even if n = 10^5, map size never exceeds a constant (like 256).
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> hash;
        int n = s.length();
        int l = 0, r = 0;
        int maxLen = 0;
        while (r < n) {
            hash[s[r]]++;
            while (hash[s[r]] > 1) {
                hash[s[l]]--;
                l++;
            }
            maxLen = std::max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};