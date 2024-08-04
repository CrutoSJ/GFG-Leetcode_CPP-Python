// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// Date-> 04/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}

class Solution {
public:
    
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int, int>> meets(n);
        for(int i=0; i<n; i++){
            meets[i].first = start[i];
            meets[i].second = end[i];
        }
        
        sort(meets.begin(), meets.end(), compare);
        
        int meetCnt=0;
        int meetEnd=-1;
        
        for(int i=0; i<n; i++){
            if(meets[i].first > meetEnd){
                meetCnt++;
                meetEnd = meets[i].second;
            }
        }
        return meetCnt;
    }
};