/*
Problem: 88. Merge Sorted Array

Problem Description:
We have two integer arrays nums1 and nums2, sorted in non-decreasing order.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.

Our Approach:
- Use two pointers and place them at the start of both the sorted arrays
- Check the element which is smaller in both the array and place it into merged array
- If the end of any of the array is reached then move the remaining 
    elements of another array into merged array (They are already sorted)

Time Complexity: O(m+n)
Space Complexity: O(m+n)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> merged_arr(m + n);
        int i = 0;  // to iterate on nums1
        int j = 0;  // to iterate on nums2
        int k = 0;  // to write into merged_arr

        // Traverse both arrays and pick the smaller element
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                merged_arr[k] = nums1[i];
                i++;
                k++;
            }
            else if (nums1[i] > nums2[j]) {
                merged_arr[k] = nums2[j];
                j++;
                k++;
            }
            else if (nums1[i] == nums2[j]) {
                merged_arr[k] = nums1[i];
                k++;
                merged_arr[k] = nums2[j];
                i++;
                j++;
                k++;
            }
        }
        // If elements remain in nums1, add them to the result
        while (i < m) {
            merged_arr[k] = nums1[i];
            i++;
            k++;
        }
        // If elements remain in nums2, move them to the merged_arr
        while (j < n) {
            merged_arr[k] = nums2[j];
            j++;
            k++;
        }

        // Copying merged_array into nums1 (As per required in question)
        for (int i = 0; i < (m + n); i++) {
            nums1[i] = merged_arr[i];
        }
    }
};



//  Alternate approach : 

/*
- Initialize three pointers at the ends of the valid elements in nums1 and nums2, 
    and one at the very end of nums1 (to write back elements)
- Compare elements from back to front to find the larger value between both arrays.
- Place the larger element into the back of nums1 to overwrite unused space safely without extra memory.
- Copy any remaining elements from nums2 into nums1 if nums2 is not fully exhausted.
  
  This solution is more efficient
Time Complexity: O(m+n)
Space Complexity: O(1)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        int i = m - 1, j = n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] <= nums2[j]) {
                nums1[k] = nums2[j];
                j--;
            }
            else {
                nums1[k] = nums1[i];
                i--;
            }
            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};