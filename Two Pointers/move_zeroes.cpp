/*
Problem: 283. Move Zeroes

Problem Description:
Given an integer array nums, move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.
Appli in-place algorithm.

Our Approach:
- Use two pointers: 'i' and 'j'
- 'i' keeps track of "where the next non-zero will be placed".
    'j' iterates through the entire array.
- When nums[j] is non-zero, we swap it with nums[i] and increment 'i'.
- when j will be at the end all the non-zeroes will be in front side of the array in relative order

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        int i = 0;
        for (int j = 0; j < sz; j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};