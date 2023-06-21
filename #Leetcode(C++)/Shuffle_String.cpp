// Question:-

// You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

// Return the shuffled string.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string restoreString(string s, vector<int>& indices) 
    {
        string sabdh=s;
        for(int i=0;i<indices.size();i++)
            sabdh[indices[i]]=s[i];
        return sabdh;
    }
};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t--){
        string s;
        cout << "Enter the string: ";
        cin >> s;
        
        int n;
        cout << "Enter the length of the string: ";
        cin >> n;
        
        vector<int> indices(n);
        cout << "Enter the indices: ";
        for(int i = 0; i < n; i++)
            cin >> indices[i];
        
        Solution obj;
        string shuffledString = obj.restoreString(s, indices);
        
        cout << "Shuffled String: " << shuffledString << endl;
    }

}