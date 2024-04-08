// #Question:-

// Given an integer N, find the absolute difference between sum of the squares of first N natural numbers and square of sum of first N natural numbers.

// Link -> https://www.geeksforgeeks.org/problems/squares-difference0939/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// #Solution:-

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long int squaresDiff(int N){
        return abs((N*(N+1)*(2*N+1))/6 - pow(N*(N+1)/2, 2));
    }
};