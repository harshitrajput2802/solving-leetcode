/*
Problem: 18. 4Sum

Problem Description:
Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:
    nums[a] + nums[b] + nums[c] + nums[d] == target
    and a, b, c, and d are distinct.
Notice that the solution set must not contain duplicate quadruplets.

Our Approach: 
- sort the array to enable the two-pointer technique and easily identify duplicate values
- We iterate through the array using a loop and fix nums[i] as one number
- then use an inner loop to iterate on remaining array and fixing nums[j] as second number
- Now use two-pointer technique to find other two numbers such that sum of all 4 numbers equals target
- In the outer-most loop, if nums[i] is the same as nums[i-1], we skip it.
- then in inner one, if nums[j] is the same as nums[j-1], we skip it.
- after finding a valid quadruplets, skip identical values for
    left and right as it would give the same result again

Time Complexity: O(n^3)
Space Complexity: O(n) -> depending on the sorting algo
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;

        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1, right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        quadruplets.push_back(
                            { nums[i], nums[j], nums[left], nums[right] });

                        left++;
                        while (left < right && nums[left] == nums[left - 1])
                            left++;

                        right--;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;

                    }
                    else if ((sum < target))
                        left++;
                    else
                        right--;
                }
            }
        }
        return quadruplets;
    }
};