// #Question:-

// Link-> https://leetcode.com/problems/different-ways-to-add-parentheses/description/?envType=daily-question&envId=2024-09-19

// Date-> 19/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(string exp){
        vector<int> result;

        for(int i=0; i<exp.length(); i++){
            if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*'){
                vector<int> left_res  = solve(exp.substr(0,i));
                vector<int> right_res = solve(exp.substr(i+1));

                for(auto &x : left_res){
                    for(auto &y : right_res){
                        if(exp[i] == '+'){
                            result.push_back(x+y);
                        } else if(exp[i] == '-'){
                            result.push_back(x-y);
                        } else{
                            result.push_back(x*y);
                        }
                    }
                }
            }
        }

        if(result.size() == 0){
            result.push_back(stoi(exp));
        }

        return result;
    }

    vector<int> diffWaysToCompute(string exp) {
        return solve(exp);
    }
};