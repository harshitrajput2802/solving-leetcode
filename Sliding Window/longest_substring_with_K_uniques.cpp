/*
Problem: Longest Substring with K Uniques
https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

Problem Description:
You are given a string s consisting only lowercase alphabets and an integer k.
Your task is to find the length of the longest substring that contains exactly k distinct characters.
Note : If no such substring exists, return -1.

Our Approach(Variable Size Sliding Window + Hashing):
- Use two pointers (low, high) to maintain a sliding window and an unordered_map to track the frequency of each character within that window.
- Expand the window by moving high and and incrementing the count of s[high] in the map.
- If the map size exceeds k (meaning we have more than unique characters)
    shrink the window from the left (low++)
    decrement the frequency of s[low] in the map
    if the frequency of s[low] == 0, remove that character from the map entirely to reduce the map size.
- update maxLen with the current window size (high - low + 1), only when the window has at most k unique characters
- Return the maxLen (or -1 if no such substring was found).

Time Complexity: O(n)
Space Complexity: O(1)

*/

class Solution {
public:
    int longestKSubstr(string& s, int k) {
        int n = s.size();
        int low = 0, high = 0;
        std::unordered_map<char, int> freq;
        int maxLen = INT_MIN;

        while (high < n) {
            freq[s[high]]++;

            while (freq.size() > k) {
                freq[s[low]]--;
                if (freq[s[low]] == 0)
                    freq.erase(s[low]);
                low++;
            }
            if (freq.size() == k)
                maxLen = std::max(maxLen, high - low + 1);
            high++;
        }
        return (maxLen != INT_MIN) ? maxLen : -1;
    }
};