// #Question:-

// Link-> https://leetcode.com/problems/number-of-atoms/description/?envType=daily-question&envId=2024-07-14

// Date-> 14/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();

        stack<unordered_map<string, int>>st;
        st.push(unordered_map<string, int>());

        int i=0;
        while(i<n){
            if(formula[i] == '('){
                st.push(unordered_map<string, int>());
                i++;
            } else if( formula[i] == ')'){
                unordered_map<string, int> curr = st.top();
                st.pop();
                i++;

                string digit;
                while((i<n) && isdigit(formula[i])){
                    digit.push_back(formula[i]);
                    i++;
                }
                
                if(!digit.empty()){
                    int digitInt = stoi(digit);
                    for(auto &it : curr){
                        string element = it.first;
                        int cnt = it.second;

                        curr[element] = cnt*digitInt;
                    }
                }

                for(auto &it : curr){
                    string element = it.first;
                    int cnt = it.second;
                    st.top()[element] +=cnt;
                }
            } else{
                string currElement;
                currElement.push_back(formula[i]);
                i++;

                while(i<n && isalpha(formula[i]) && islower(formula[i])){/// if element is He, Mg etc..
                    currElement.push_back(formula[i]);
                    i++;
                }

                string digit;
                while(i<n && isdigit(formula[i])){
                    digit.push_back(formula[i]);
                    i++;
                }

                int digitInt = digit.empty() ? 1 : stoi(digit);
                st.top()[currElement] += digitInt;
            }
        }

        map<string, int>sortedMap(st.top().begin(), st.top().end());
        string results;

        for(auto &it : sortedMap){
            string element = it.first;
            results += element;
            int cnt = it.second;
            if(cnt>1){
                results += to_string(cnt);
            }
        }

        return results;
    }
};