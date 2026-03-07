/*
Problem: 1. 3Sum Closest

Problem Description:
Given an integer array nums of length n and an integer target, find three integers 
at distinct indices in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.
nums.length >= 3


Our Approach: (Two Pointers)
- we have to find the sum of three integer whose sum is closest to the target 
    ,i.e, difference between their sum and target should bbe minimun
- we will keep track the minimum-sum 
- sort the array to enable the two-pointer technique
- We will just use the 3 Sum logic to calculate the sum
- if (currentSum == target) return this currentSum as this is the best condition
- if absolute value of (the difference between target and currentSum) is less than  
    absolute value (of the difference between target and minimumSum) then update the minimum sum to currentsum
- update the left pointer if currentSum < target or else rightt one

Time Complexity: O(n^2)
Space Complexity: O(n) -> depending on the sorting algo
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minSum = nums[0] + nums[1] + nums[2];
        int minDiff = INT_MAX;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (currentSum == target)
                    return currentSum;

                if (std::abs(target - currentSum) < std::abs(target - minSum)) {
                    minSum = currentSum;
                }

                if (currentSum < target)
                    left++;
                else
                    right--;
            }
        }
        return minSum;
    }
};