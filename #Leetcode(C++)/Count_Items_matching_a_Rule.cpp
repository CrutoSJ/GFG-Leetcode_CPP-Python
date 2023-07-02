// #Question:-

// You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

// The ith item is said to match the rule if one of the following is true:

// ruleKey == "type" and ruleValue == typei.
// ruleKey == "color" and ruleValue == colori.
// ruleKey == "name" and ruleValue == namei.
// Return the number of items that match the given rule.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int n = items.size();
        int count = 0;

        int ruleK;
        if(ruleKey == "type"){
            ruleK = 0;
        } else if (ruleKey == "color"){
            ruleK = 1;
        } else {
            ruleK = 2;
        }

        for(int i = 0; i < n; i++){
            if(items[i][ruleK] == ruleValue){
                count++;
            }
        }
        return count;
    }
};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the number of items: ";
        cin >> n;

        vector<vector<string>> items(n, vector<string>(3));
        for(int i = 0; i < n; i++){
            cout << "Enter the type, color, and name of item " << i+1 << ": ";
            cin >> items[i][0] >> items[i][1] >> items[i][2];
        }

        string ruleKey, ruleValue;
        cout << "Enter the rule key: ";
        cin >> ruleKey;
        cout << "Enter the rule value: ";
        cin >> ruleValue;

        Solution obj;
        int result = obj.countMatches(items, ruleKey, ruleValue);
        cout << "Number of items matching the rule: " << result << endl;
    }
    return 0;

}