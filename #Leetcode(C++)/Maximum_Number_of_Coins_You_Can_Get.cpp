#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxCoins(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans = 0;
        for(int i = 0,j = arr.size()-1;i<j;j-=2,i+=1)
        ans+=arr[j-1];
        return ans; 
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    while(t--){
        int n;
        cout << "Enter the number of coins: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter the values of coins: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution sol;
        int result = sol.maxCoins(arr);
        cout << "Maximum coins that can be obtained: " << result << endl;
    }

    return 0;
}