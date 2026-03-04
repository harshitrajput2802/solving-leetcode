/*
Problem: 66. Plus One  
You are given a large integer represented as an integer array digits, where each digits[i]
is the ith digit of the integer. The digits are ordered from most significant to 
least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Input: digits = [1,2,3]
Output: [1,2,4]

Our Approach:
- check the last digit
    -> if it is not 9 then simply add 1 and return the array
    -> if it is 9 the make it zero and increment the previous digit and then return the array
- if the array has all 9's then we will resize the array with incrementing it's size
    and filling all 0 and making the first digit 1

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int number = 0;
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            else {
                digits[i] = 0;
            }
        }
        digits.resize(n + 1, 0);
        digits[0] = 1;

        return digits;
    }
};