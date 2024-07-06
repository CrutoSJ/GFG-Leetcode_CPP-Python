// #Question:-

// Link-> https://leetcode.com/problems/pass-the-pillow/

// Date-> 06/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int a = time/(n-1);
        int b = time%(n-1);

        if(a%2 == 0){//even rounds - moving forward
            return b+1;
        } else{
            return n-b;
        }
    }
};