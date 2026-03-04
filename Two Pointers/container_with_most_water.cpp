/*
Problem: 11. Container with Most Water

Problem Description:
You are given an integer array height of length n. There are n vertical lines drawn such 
that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.

Brute Force:
- evaluate water for all possible pairs of lines in the array
Time Complexity: O(n^2)

Our Approach: (Two Pointers + Greedy)
- water trapped is calculated as (minimun heigth of vertical lines) * distance between then
- Use two pointers: 'i' at the start and 'j' at the end, this will give the largest width at starting
- But as the pointer will move inward the width will be reduced,
    so in-order to increase area we have to find a taller vertical line
- Now we should always move the pointer pointing to the shorter line because
    we might find a taller line that could potentially create a larger area despite the reduced width
- we will calculate the water trapped and also find the max_water every time.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int water = 0, max_water = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            int width = right - left;
            water = std::min(height[left], height[right]) * width;
            max_water = std::max(water, max_water);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_water;
    }
};