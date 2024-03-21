// #Question:-

// Link-> https://www.codingninjas.com/studio/problems/flip-bits_8160405

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int flipBits(int A, int B){
    int count=A^B,ans=0;
    while(count!=0)
    {
        ans+=(count&1?1:0);
        count=count>>1;
    }
    return ans;
}