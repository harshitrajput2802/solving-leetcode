/*
Problem: 268. Missing Number

Our Approach:
- Sum of first n numbers, N = n * (n+1)/2
- Missing number = Sum of array elements - N

Time Complexity: O(n)
Space Complexity: O(1)

Alternative Approach:
- XOR all numbers from 0 to n
- XOR all elements of the array
- Missing number remains as, [a ^ a = 0] and  [0 ^ b = b]

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missingNum = (n + 1) * (n) / 2;
        for (int i = 0; i < n; i++) {
            missingNum -= nums[i];
        }
        return missingNum;
    }
};