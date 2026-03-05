/*
Problem: 11. Container with Most Water

Problem Description:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Brute Force:
- use three nested for loops (indices i, j, and k) to check 
    every possible combination of three numbers in the array.    
- For every combination, we check if sum of three number is equal to zero or not
- we must store the found triplets in a Set to avoid duplicate triplets
Time Complexity: O(n^3)
Space Complexity: O(n)

Our Approach: (Two Pointers + Greedy)
- sort the array to enable the two-pointer technique and easily identify duplicate values
- We iterate through the array using a loop and fix nums[i] as one number 
    and find other two numbers whose sum = -nums[i]
- for each nums[i], we use two pointer at both the ends of array to find other two numbers
- In the outer loop, if nums[i] is the same as nums[i-1], we skip it.
    We have already explored all possible triplets starting with
    that specific value in the previous iteration
- after finding a valid triplet, skip identical values for 
    left and right as it would give the same result again

Time Complexity: O(n^2)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<vector<int>> triplets;
        int count = 0;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Optimization: If the smallest number is > 0, no triplet can sum to 0
            if (nums[i] > 0) break;

            // Skip the same 'i' to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1, right = n - 1;
            int pairSum = -nums[i];

            while (left < right) {
                int currentSum = nums[left] + nums[right];

                if (currentSum == pairSum) {
                    triplets.push_back({ nums[i], nums[left], nums[right] });
                    // Move pointers first before checking for duplicates
                    left++;
                    right--;

                    // Skip the same 'left' and 'right' values to ensure uniqueness
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (currentSum < pairSum) {
                    left++;
                }
                else
                    right--;
            }
        }
        return triplets;
    }
};