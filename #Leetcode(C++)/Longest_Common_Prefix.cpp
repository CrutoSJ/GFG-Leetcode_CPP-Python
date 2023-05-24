// #Question:-

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};

int main(){
        int t;
        cout << "Enter the no. of test cases: ";
        cin >> t;
        while(t--){
            int n;
            cout << "Enter the number of strings: ";
            cin >> n;
            vector<string> v(n);
            cout << "Enter the strings: " << endl;
            for (int i = 0; i < n; i++) {
                cin >> v[i];
            }
            Solution sol;
            string result = sol.longestCommonPrefix(v);
            cout << "Longest Common Prefix: " << result << endl;
        }
    return 0;
}