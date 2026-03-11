/*
Problem: 26. Remove duplicates from Sorted Array

Problem Decription:
Given an integer array nums sorted in non-decreasing order,
remove the duplicates in-place such that each unique element appears only once.
The relative order of the elements should be kept the same.

Our Approach:
- Use two pointers: i' (slow pointer) and 'j' (fast pointer)
- 'i' tracks the position where the next unique element should be placed
- 'j' iterates over the array to find elements different from the last unique element
- When a new element is found, copy it to nums[i] and increment 'i'
- The number of unique elements is the final value of 'i'

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int i = k;
        int n = nums.size();
        if (n <= k)
            return n;

        for (int j = k; j < n; j++) {
            if (nums[j] != nums[i - k]) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};