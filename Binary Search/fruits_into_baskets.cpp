/*
Problem: 904. Fruits into Baskets

Problem Description:
You are walking along a row of fruit trees, each represented by an integer (its type).
You have two baskets, and each basket can only hold one type of fruit.
You want to collect the maximum total number of fruits possible.

You must stop as soon as you reach a tree with a third type of fruit that doesn't fit in your baskets.
You must also collect fruits from trees in a continuous sequence.

We just have to find the length of the longest subarray containing at most two distinct integers.

Our Approach(Variable Size Sliding Window + Hashing):
- Use two pointers (low, high) to maintain a sliding window and an unordered_map to track the types of fruits in your baskets and how many of each you have.
- Expand the window by moving high and and incrementing the count of fruits[high] in the map.
- If the map size exceeds 2 (meaning we have more than 2 distinct fruits)
    shrink the window from the left (low++)
    remove fruits from the left until we are back down to only two types in your baskets.
- update maxFruits with the current window size (high - low + 1)
- Return the maxFruit count

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
            maxLen = std::max(maxLen, high - low + 1);
            high++;
        }
        return (maxLen != INT_MIN) ? maxLen : -1;
    }
};