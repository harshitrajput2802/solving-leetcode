/*
Problem: 845. Longest Mountain in Array

Problem Description:
You may recall that an array arr is a mountain array if and only if:
    1. arr.length >= 3
    2. There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
        arr[0] < arr[1] < ... < arr[i - 1] < arr[i] and
        arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. 
Return 0 if there is no mountain subarray.

Our Approach : 
- We will use two pointer 'start' and 'end' to traverse the array
- First, skip all the invalid starting points (flat or decreasing elements)
- Now once we got the starting point we will place both pointers at start
- Using 'end' pointer find the peak from the increasing slope(uphill)
- This is our 'peak'
- Now continue moving 'end' on decreasing slope(downhill)
- If a valid downhill exists (end > peak), then we will calculate the mountain length (end - start + 1)
- Also update the maximum length
- Set start = end to continue searching for the next mountain


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3)
            return 0;
        int start = 0, end = 0;
        int maxLen = 0;

        while (start < n - 2) {
            // find the valid starting point of the mountain
            // we will skip flat surface and initial decreasing slope
            while (start < n - 1 && arr[start] >= arr[start + 1])
                start++;

            end = start; // we have got the starting index of the mountain

            // now we will find the peak from the left slop of mountain
            while (end < n - 1 && arr[end] < arr[end + 1])
                end++;

            int peak = end; // this is our peak index

            // now we will move downhill
            while (end < n - 1 && arr[end] > arr[end + 1])
                end++;

            // if downhill happened then calculate maximum lengthn
            if (end > peak) {
                maxLen = std::max(maxLen, end - start + 1);
            }

            // once we have reached the end of mountain we will set the start at
            // this point as there may be many mountains in the preceding part
            // of the array
            start = end;
        }
        return maxLen;
    }
};