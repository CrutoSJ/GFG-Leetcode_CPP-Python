// #Question:-

// Link-> https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

// Date-> 13/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int moves=0;
        for(int i=0; i<seats.size(); i++){
            moves+= abs(seats[i]-students[i]);
        }
        return moves;
    }
};