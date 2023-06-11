// Question:-

// You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

// Letters are case sensitive, so "a" is considered a different type of stone from "A".

// Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int numJewelsInStones(string jewels, string stones){
        int n = stones.size();
        int ans = 0;
        for(int i=0; i<jewels.size(); i++){
            for(int j=0; j<n; j++){
                if(jewels[i] == stones[j]){
                    ans = ans + 1;
                }
            }
        }
        return ans;
        
    }

};

int main() {
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while (t--) {
        string jewels, stones;
        cout << "Enter the jewels: ";
        cin >> jewels;
        cout << "Enter the stones: ";
        cin >> stones;
        
        Solution obj;
        int result = obj.numJewelsInStones(jewels, stones);
        
        cout << "Number of stones that are also jewels: " << result << endl;
    }
    return 0;
}