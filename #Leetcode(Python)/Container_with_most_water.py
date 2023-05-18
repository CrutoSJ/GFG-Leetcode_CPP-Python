# Question:-

# You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
# Find two lines that together with the x-axis form a container, such that the container contains the most water.
# Return the maximum amount of water a container can store.
# Notice that you may not slant the container.

# Solution:-

from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        left,right,answer=0,len(height)-1,0
        while (left <= right):
            area = min(height[right],height[left])*(right-left)
            answer = max(answer,area)
            if height[right]>height[left]:
                left+=1
            else:
                right-=1
        return answer

t = int(input("Enter no. of test cases: "))
for i in range (0,t):

    height = input("Enter comma-separated integers: ")
    height = [int(x) for x in height.split(",")]

    s = Solution()
    result= s.maxArea(height)
    print("Result: ", result)
