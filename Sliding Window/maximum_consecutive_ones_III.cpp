/*
Problem: 1004. Maximum Consecutive Ones III

Problem Description:
Given a binary array nums and an integer k,
return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

- So we have to find the longest subarray containing at most zeros

Our Approach(Sliding Window):
- We use two pointers (low, high) to maintain a window
- we will also track the number of atmost zeros we can have as 'flips = k'
- Expand the window by moving high and include nums[high] in the our window
- If we encounter '0', then we will decrease the flips count
- If at any point 'flips < 0'
    we will shrink the window from the left (low++) until the window becomes valid
    only increment flips if the element leaving the window (nums[low]) was a 0
- return the maximum window length found

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int flips = k;
        int low = 0;

        for (int high = 0; high < n; high++) {
            if (nums[high] == 0)
                flips--;

            while (flips < 0) {
                if (nums[low] == 0)
                    flips++;
                low++;
            }
            maxLen = std::max(maxLen, high - low + 1);
        }
        return maxLen;
    }
};

/*
More Optimized approach (Non-Shrinking Window) : 
- Instead of using a while loop to shrink the window back to a valid state, 
    we only move the left pointer(low) at most once per step.
- This keeps the window size at the maximum length found so far.
- If the window becomes invalid(more than
    zeros), it simply "slides" forward without growing until it finds another valid segment.
- This approach only works when we specifically need the maximum length.
- This optimized version is a "pro" trick that's great for competitive programming

Time Complexity : O(n)
Space Complexity : O(1)
*/

int longestOnes(vector<int>& nums, int k) {
    int low = 0, high = 0;
    int n = nums.size();

    for (high = 0; high < n; high++) {
        if (nums[high] == 0) k--;

        // If invalid, slide the window (don't shrink it)
        if (k < 0) {
            if (nums[low] == 0) k++;
            low++;
        }
    }
    // The distance between high and low is the maximum window size ever reached
    return high - low;
}