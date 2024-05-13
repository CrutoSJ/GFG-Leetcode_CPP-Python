// #Question:-

// Link-> https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        int n = students.size();
        
        for(int i : students){
            q.push(i);
        }
        
        int j=0, count=0;
        
        while(!q.empty()){
            int val = q.front();
            q.pop();
            if(val == sandwiches[j]){
                j++;
                count=0;
            }
            else{
                count++;
                q.push(val);
            }
            
            if(count == n){
                return n-j;
            }
        }
        
        return 0;
    }
};