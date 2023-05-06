# Question:-

# Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
# The overall run time complexity should be O(log (m+n)).

# Solution:-

from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        m, n = len(nums1), len(nums2)
        imin, imax, half_len = 0, m, (m + n + 1) // 2
        while imin <= imax:
            i = (imin + imax) // 2
            j = half_len - i
            if i < m and nums2[j-1] > nums1[i]:
                imin = i + 1
            elif i > 0 and nums1[i-1] > nums2[j]:
                imax = i - 1
            else:
                if i == 0: 
                    maxLeft = nums2[j-1]
                elif j == 0: 
                    maxLeft = nums1[i-1]
                else: 
                    maxLeft = max(nums1[i-1], nums2[j-1])
                if (m + n) % 2 == 1:
                    return maxLeft
                if i == m: 
                    minRight = nums2[j]
                elif j == n: 
                    minRight = nums1[i]
                else: 
                    minRight = min(nums1[i], nums2[j])
                return (maxLeft + minRight) / 2.0
            
t = int(input("Enter no. of test cases: "))
for i in range (0,t):

    nums1 = input("Enter comma-separated integers: ")
    nums1 = [int(x) for x in nums1.split(",")]

    nums2 = input("Enter comma-separated integers: ")
    nums2 = [int(x) for x in nums2.split(",")]

    s = Solution()
    result = s.findMedianSortedArrays(nums1,nums2)
    print("Result:", result)