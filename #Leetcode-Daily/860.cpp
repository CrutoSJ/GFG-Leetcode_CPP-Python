// #Question:-

// Link-> https://leetcode.com/problems/lemonade-change/description/?envType=daily-question&envId=2024-08-15

// Date-> 15/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                five++;
            }
            else if (bills[i] == 10){
                if(five == 0){
                    return false;
                }
                five--;
                ten++;
            }
            else{
                if(five>0 && ten>0){
                    five--;
                    ten--;
                } else if(five>= 3){
                    five -= 3;
                } else{
                    return false;
                }
            }
        }
        return true;
    }
};