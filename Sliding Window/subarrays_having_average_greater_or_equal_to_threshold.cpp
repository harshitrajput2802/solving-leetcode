/*
Problem: 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

Problem Description:
Given an array of integers arr and two integers k and threshold,
return the number of sub-arrays of size k and average greater than or equal to threshold.

Our Approach(Sliding Window):
- instead of finding average we can see this problem as : "sum/k >= threshold" this means "sum >= (threshold * k)"
    so our target is (threshold * k)
- So we have to find the number of subarrays whose sum >= target
- Calculate the sum of first k elements => This will be our window
- check if sum >= targetSum then increment count
- Use a loop starting from index k to the end of the array,
    add new element and remove thhe old one -> sliding the window
- after each slide, check if (sum >= targetSum) then increment count
- At the end we will have the count of number of subarrays so it will be returned

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // "sum/k >= threshold" this means "sum >= (threshold * k)"
        int n = arr.size();
        int targetSum = threshold * k;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        if (sum >= targetSum)
            count++;
        for (int i = k; i < n; i++) {
            sum -= arr[i - k];
            sum += arr[i];
            if (sum >= targetSum)
                count++;
        }
        return count;
    }
};