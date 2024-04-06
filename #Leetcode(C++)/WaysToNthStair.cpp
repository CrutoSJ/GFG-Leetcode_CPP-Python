// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1

// There are n stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. 
// Count the number of ways, the person can reach the top (order does not matter).

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        // your code here
        long long cnt = 0;
        cnt=n/2;
        cnt+=1;
        return cnt;
    }
};