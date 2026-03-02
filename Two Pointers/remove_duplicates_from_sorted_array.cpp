/*
Problem: 26. Remove duplicates from Sorted Array

Our Approach:
- Use two pointers: i' (slow pointer) and 'j' (fast pointer)
- 'i' points to the last unique element found
- 'j' iterates over the array in search for element different from nums[i]
- When a new element is found, increment 'i' and copy the value at 'j' to this position
- number of unique element is equal to i+1

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = i + 1;
        int sz = nums.size();
        while (j < sz) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i + 1;
    }
};