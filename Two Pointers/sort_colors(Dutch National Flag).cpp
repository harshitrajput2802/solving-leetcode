/*
Problem: 75. Sort Colors

Problem Description:
Given an array nums with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
We do not have to use library's sort function.

Our Approach (Dutch National Flag Algorithm): 
- we have to maintain three zones
    [0 … low-1] -> all 0s
    [low … mid-1] -> all 1s
    [high+1 … n-1] -> all 2s and we have to process the unknown region : [mid … high]
- we will use three pointers
    low -> for placing next 0
    high -> for placing next 2
    mid -> for current element
- We'll traverse the array until mid <= high:
    if 0 is found then we will swap it with low pointer element;        increment low and mid
    if 2 is found then we will swap it with high pointer element;       decrement high only and mid
    else(1), we will do nothing as it is in correct relative position;  increment mid only
- we don't increment mid when we swap with high because the element coming from high is unknown
    (we may swap 2(from higher side) and place it in lower side) -> so we have to check it again

Dutch National Flag Algorithm :
It is an in-place partitioning algorithm used to sort an array with three distinct values
by dividing it into three regions in one pass.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (nums[mid] == 0)
                std::swap(nums[mid++], nums[low++]);

            else if (nums[mid] == 2)
                std::swap(nums[mid], nums[high--]);
            else
                mid++;
        }
    }
};