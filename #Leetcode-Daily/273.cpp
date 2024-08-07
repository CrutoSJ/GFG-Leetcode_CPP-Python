// #Question:-

// Link-> https://leetcode.com/problems/integer-to-english-words/description/?envType=daily-question&envId=2024-08-07

// Date-> 07/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
        unordered_map<int, string> underTen { {0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
                        {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"} };

        unordered_map<int, string> underTwenty { {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, 
                        {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, 
                        {19, "Nineteen"} };

        unordered_map<int, string> underHundred { {2, "Twenty"}, {3, "Thirty"}, {4,"Forty"}, {5, "Fifty"},
                        {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"} };

    string solve(int num){
        if(num<10){
            return underTen[num];
        }

        if(num<20){
            return underTwenty[num];
        }

        if(num<100){ //89 --> Eighty Nine
            return underHundred[num/10] + ((num%10) != 0 ? " " + solve(num%10) : ""); 
        }

        if(num<1000){ //973 --> Nine Hundred Seventy Three
            return solve(num/100) + " Hundred" + ((num%100) != 0 ? " " + solve(num%100) : "");
        }

        if(num<1000000){ // 89,763 --> Eighty Nine Thousand Seven Hundred Sixty Three
            return solve(num/1000) + " Thousand" + ((num%1000) != 0 ? " " + solve(num%1000) : "");
        }

        if(num<1000000000){
            return solve(num/1000000) + " Million" + ((num%1000000)  != 0 ? " " + solve(num%1000000) : "");
        }

        return solve(num/1000000000) + " Billion" + ((num%1000000000) != 0 ? " " + solve(num%1000000000) : "");
    }

    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }

        return solve(num);
    }
};