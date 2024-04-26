// #Question:-

// We are playing the Guess Game. The game is as follows:

// I pick a number from 1 to n. You have to guess which number I picked.

// Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

// You call a pre-defined API int guess(int num), which returns three possible results:

// -1: Your guess is higher than the number I picked (i.e. num > pick).
// 1: Your guess is lower than the number I picked (i.e. num < pick).
// 0: your guess is equal to the number I picked (i.e. num == pick).
// Return the number that I picked.

// #Link-> https://leetcode.com/problems/guess-number-higher-or-lower/

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
    int guess(int num);
    
public:
    int guessNumber(int n) {
        int s=1;
        int e=n;
        
        int mid = s+(e-s)/2;
        
        while(s<=e){
            if(guess(mid) == 0){
                break;
            }
            
            if(guess(mid) == -1){
                e=mid-1;
            }
            
            if(guess(mid) == 1){
                s=mid+1;
            }
            
            mid = s+(e-s)/2;
        }
        
        return mid;
    }
};