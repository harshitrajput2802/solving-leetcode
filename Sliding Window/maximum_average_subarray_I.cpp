/*
Problem: 643. Maximum Average Subarray I

Problem Description:
You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value.

Our Approach(Sliding Window):
- Calculate the sum of the first k elements => This will be our window
- Keep this sum as maxSum
- Use a loop starting from index k to the end of the array, 
    adding the new element at the current index and 
    subtracting the old element that is k positions behind it.
- new element will be at index 'i' and old element will be at index 'i-k'
- after each slide, store the maximum of sum and maxSum
- At the end we will have the maximum sum, to return the average we will divide it by k and return it

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double maxSum = sum;
        for (int i = k; i < n; i++) {
            sum += nums[i];
            sum -= nums[i - k];
            maxSum = std::max(maxSum, sum);
        }
        return maxSum / k;
    }
};