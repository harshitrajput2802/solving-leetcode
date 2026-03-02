/*
Problem: 977. Squares of Sorted Array

Brute Force:
 - store the square of each element as per their indices in another array then sort the array
 Time Complexity: O(n logn)
Space Complexity: O(n)

Our Approach:
- Use two pointers: one at the start and one at the end of the sorted array
- Since the array is sorted, the largest square value must be at one of these end
- compare the absolute values of array elements at 'i' and 'j'
- Fill the resulting array from last(largest value at the end) with
    the square of the element with larger absolute value

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int sz = nums.size();
        int i = 0, j = sz - 1;
        int k = sz - 1;
        std::vector<int> squared_array(sz);
        while (i <= j) {
            // Here we can also use std::abs() for comparing absolute values
            // but it will create unecessary functional call overheads
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                squared_array[k--] = nums[j] * nums[j];
                j--; // Move the right pointer inward
            }
            else {
                squared_array[k--] = nums[i] * nums[i];
                i++; // Move the left pointer inward
            }
        }
        return squared_array;
    }
};