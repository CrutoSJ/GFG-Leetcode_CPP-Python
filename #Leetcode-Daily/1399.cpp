// #Question:-

// Link-> https://leetcode.com/problems/count-largest-group/description/?envType=daily-question&envId=2025-04-23

// Date-> 23/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findSum(int num){
            int sum = 0;
            while(num){
                sum += num%10;
                num /= 10;
            }
            return sum;
        }
        int countLargestGroup(int n) {
            unordered_map<int,int> mp;
    
            int cnt=0;
            int max=0;
    
            for(int i=1; i<=n; i++){
                int sum = findSum(i);
                mp[sum]++;
    
                if(mp[sum] == max){
                    cnt++;
                } else if(mp[sum] > max){
                    max = mp[sum];
                    cnt = 1;
                }
            }
            return cnt;
        }
    };