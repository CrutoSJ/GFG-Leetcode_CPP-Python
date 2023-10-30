// #Question-

// You are given an integer array pref of size n. Find and return the array arr of size n that satisfies:

// pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
// Note that ^ denotes the bitwise-xor operation.

// It can be proven that the answer is unique.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        int n=pref.size();
        ans.push_back(pref[0]);
        for(int i=1;i<n;i++)
        {
           ans.push_back(pref[i-1]^pref[i]);
        }
        return ans;
        
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the size of the pref array: ";
        cin >> n;

        vector<int> pref(n);
        cout << "Enter the elements of the pref array: ";
        for (int i = 0; i < n; i++) {
            cin >> pref[i];
        }

        Solution solution;
        vector<int> arr = solution.findArray(pref);

        cout << "The arr array is: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}