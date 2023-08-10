// #Question:-

// Alice and Bob take turns playing a game, with Alice starting first.

// Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

// Choosing any x with 0 < x < n and n % x == 0.
// Replacing the number n on the chalkboard with n - x.
// Also, if a player cannot make a move, they lose the game.

// Return true if and only if Alice wins the game, assuming both players play optimally.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divisorGame(int n) {
        if(n % 2 == 0){
            return true;
        }
        return false;
    }
};

int main() {
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    
    Solution solution; // Create an instance of the Solution class
    
    while(t--) {
        int n;
        cout << "Enter n for the test case: ";
        cin >> n;
        
        bool aliceWins = solution.divisorGame(n); // Call the solution function
        
        if (aliceWins) {
            cout << "Alice wins!" << endl;
        } else {
            cout << "Alice loses!" << endl;
        }
    }
    
    return 0;
}
