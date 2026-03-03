/*
Problem: 27. Remove element

Problem Description:
Given an integer array nums and an integer val, remove all occurrences of val in-place and 
return the number of elements that are not equal to val.
The order of elements does not matter

Our Approach:
- Use two pointers: 'i' at the start and 'j' at the end
- 'i' finds the element to be removed from the left and 
    'j' points to the end of the array and provides a replacement element when needed
- if nums[i] != val => that means we need not to remove this element so we will move ahead, i++
- if nums[i] == val => so we have to remove this element
    so we will replace it with nums[j] and move 'j' inwards
- 'i' moves only when the element is valid(not equal to val)
- All elements beyond 'j' is unwanted
- When the loop ends, indices [0 ... i-1] contain all valid elements.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz = nums.size();
        int i = 0;
        int j = sz - 1;
        while (i <= j) {
            if (nums[i] == val) {
                nums[i] = nums[j];
                j--;
            }
            else {
                i++; // Element is valid, keep it and move forward
            }
        }
        return i;
    }
};