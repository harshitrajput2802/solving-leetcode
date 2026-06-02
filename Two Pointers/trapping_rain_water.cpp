/*
Problem: 42. Trapping Rain Water

Problem Description:
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Here,
Water trapped for each bar will be calculated as :
minimun of ((maximum height of a bar on its left side) and (maximum height of a bar on its right side )) - height of that bar

Brute Force:
- Calculate water trapperd for each bar and find the total sum
Time Complexity: O(n^2)     Space Complexity: O(1)

Better Approach: (Prefix Sum)
- Create two arrays leftMax[] and rightMax[] and for each bar store the 
    left maximum height and right maximum height in respective arrays
- Now at each index calculate the water trapped and find the total sum
Time Complexity: O(n)     Space Complexity: O(n)
*/

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        std::vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            if (height[i] > leftMax[i - 1])
                leftMax[i] = height[i];
            else
                leftMax[i] = leftMax[i - 1];
        }

        std::vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i > 0; i--) {
            if (height[i] > rightMax[i + 1])
                rightMax[i] = height[i];
            else
                rightMax[i] = rightMax[i + 1];
        }

        int water = 0;
        for (int i = 1; i < n - 1; i++) {
            water += std::min(leftMax[i], rightMax[i]) - height[i];
        }
        return water;
    }
};

/*
More better Approach: (Two Pointers)
 One important obsvation is that Water depends only on smaller of leftMax and rightMax.
 So we don't need BOTH values at all times.
- Use two pointers (left, right) starting from both ends and maintain:
    - leftMax -> maximum height seen so far from the left
    - rightMax -> maximum height seen so far from the right
- At each step we compare height[left] and height[right] and
  process the side with smaller height because its water level is limited by its own side.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3)
            return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = std::max(height[left], leftMax);
                totalWater += leftMax - height[left];
                left++;
            }
            else {
                rightMax = std::max(height[right], rightMax);
                totalWater += rightMax - height[right];
                right--;
            }
        }
        return totalWater;
    }
};