/*
Problem: 86. Remove duplicates from Sorted Array II

Problem Decription:
Given an integer array nums sorted in non-decreasing order, 
remove some duplicates in-place such that each unique element appears at most twice.
The relative order of the elements should be kept the same.

Our Approach:
- Use a general 'k' value (k=2) to allow each element to appear at most 'k' times.
- Use two pointers: 'i' (slow/write pointer) and 'j' (fast/scan pointer).
- Since the array is sorted, we compare the current element nums[j] with the
  element placed 'k' positions ago (nums[i-k]).
- If they are different, it means we haven't exceeded the 'k' limit for that value.
- When a valid element is found, copy nums[j] to nums[i] and increment 'i'.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;
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