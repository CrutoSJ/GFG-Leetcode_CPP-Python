#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string finalString(string s) {
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]=='i'){
                reverse(res.begin(),res.end());
            }
            else res+=s[i];
        }
        return res;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    cin.ignore();

    Solution sol;
    while(t--){
        string input;
        cout << "Enter a string: ";
        getline(cin, input);
        
        string result = sol.finalString(input);
        cout << "Final string: " << result << endl;
    }

    return 0;
}