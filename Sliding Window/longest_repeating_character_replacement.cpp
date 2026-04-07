/*
Problem: 424. Longest Repeating Character Replacement

Problem Description:
Find the longest substring which have the same character and we can replace at most 'k' charcters to make the characters same.

Our Approach(Variable Size Sliding Window + Hashing):
- We use two pointers (high, low) to maintain a window and an unordered_map to store frequency of characters inside the window
- Expand the window by moving high and include s[high] in the map
- Maintain a variable maxFreq to store the maximum frequency of any character in the current window
- Check that our window is valid by the condition : (window size - maxFreq) <= k
    if not then shrink until the window becomes valid again
- At every valid window, calculate its length (high - low + 1) and update the maximum window lenght'maxLen'
- Continue this process until high reaches the end of the string

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> hashMap;
        int n = s.size();
        int low = 0, maxFreq = 0;
        int maxLen = 0;

        for (int high = 0; high < n; high++) {
            hashMap[s[high]]++;
            maxFreq = std::max(maxFreq, hashMap[s[high]]);

            while ((high - low + 1) - maxFreq > k) {
                hashMap[s[low]]--;
                low++;
            }
            maxLen = std::max(maxLen, high - low + 1);
        }
        return maxLen;
    }
};