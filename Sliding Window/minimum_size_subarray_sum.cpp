/*
Problem: 209. Minimum Size Subarray Sum

Problem Description:
Given an array of positive integers nums and a positive integer target,
return the minimal length of a subarray whose sum is greater than or equal to target.
If there is no such subarray, return 0 instead.

Our Approach(Sliding Window):
- So we have to find the number of number elements whose sum >= target
- We use two pointers (low, high) to maintain a window
- Expand the window by moving high and include nums[high] in the our current sum
- if at any point the sum exceeds the target
    we will calculate the window length and shrink the window from the left (low++)
    until the window is no longer valid
- return the minimun length calculated or '0' if no such substring present

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0, high = 0;
        int n = nums.size();
        int sum = 0;
        int minLen = INT_MAX;
        while (high < n) {
            sum += nums[high];
            while (sum >= target) {
                minLen = std::min(minLen, high - low + 1);
                sum -= nums[low];
                low++;
            }
            high++;
        }
        if (minLen == INT_MAX)
            return 0;
        else
            return minLen;
    }
};