// #Question:-

// You are given an integer n, the number of teams in a tournament that has strange rules:

// If the current number of teams is even, each team gets paired with another team. A total of n / 2 matches are played, and n / 2 teams advance to the next round.
// If the current number of teams is odd, one team randomly advances in the tournament, and the rest gets paired. A total of (n - 1) / 2 matches are played, and (n - 1) / 2 + 1 teams advance to the next round.
// Return the number of matches played in the tournament until a winner is decided.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int numberOfMatches(int n) {
        int count=0;
        while(n>1)
        { 
            if(n%2==0)
            {
            int a=n/2;
            n=n/2;
            count=count+a;}
            else
            {
                int a=(n-1)/2;
                n=a+1;
                count=count+a;
            }            
        }
        return count;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the number of teams: ";
        cin >> n;

        Solution sol;
        int matches = sol.numberOfMatches(n);
        cout << "Number of matches played until a winner is decided: " << matches << endl;
    }
    return 0;
    
}