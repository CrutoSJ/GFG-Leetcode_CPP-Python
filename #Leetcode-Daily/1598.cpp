// #Question:-

// Link-> https://leetcode.com/problems/crawler-log-folder/description/

// Date-> 10/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(int i=0; i<logs.size(); i++){
            if(cnt<0) cnt =0;
            if(logs[i] == "./")continue;
            else if(logs[i] == "../") cnt--;
            else cnt++;
        }
        if(cnt<0) return 0;
        return cnt;
    }
};