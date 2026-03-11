/*
Problem: 167. Two Sum II - Input Array is Sorted

Problem Description:
Given a 1-indexed array of integers sorted in non-decreasing order,
find two numbers such that they add up to a specific target number.
Return the indices of the two numbers index1 and index2, each incremented by one,\
as an integer array [index1, index2] of length 2.

Our Approach:
- Use two pointers: one at the start and one at the end of the sorted array
- calculate sum of the elements present at the 'left' and 'right' index
- if sum = target then this is our required indices
- if sum is too small, move the left pointer forward to increase the sum
- if sum is too large, move the right pointer backward to decrease the sum

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::vector<int> indices;
        
        // Initialize two pointers: one at the start and one at the end of the sorted array
        int left = 0, right = numbers.size() - 1;

        // Continue searching as long as the pointers don't cross
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                indices.push_back(left + 1);
                indices.push_back(right + 1);
                return indices; // 1-based indexing
            }
            else if (sum < target) {
                left++;
            }
            else if (sum > target) {
                right--;
            }
        }
        
        // Return an empty vector if no solution is found
        return {};
    }
};