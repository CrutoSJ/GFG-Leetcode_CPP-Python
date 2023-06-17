// Question:-

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sj;
        
        for (auto x : strs) {
            string temp = x;
            sort(temp.begin(), temp.end());
            
            sj[temp].push_back(x);
        }
        
        vector<vector<string>>Output;
        
        for (auto it : sj) {
            Output.push_back(it.second);
        }
        
        return Output;
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
        
        vector<string> strs(n);
        cout << "Enter the strings:\n";
        for (int i = 0; i < n; i++) {
            cin >> strs[i];
        }
        
        Solution sol;
        vector<vector<string>> result = sol.groupAnagrams(strs);
        
        cout << "\nAnagram groups:\n";
        for (const auto& group : result) {
            for (const auto& str : group) {
                cout << str << " ";
            }
            cout << endl;
        }

    }
    
    return 0;
    

}