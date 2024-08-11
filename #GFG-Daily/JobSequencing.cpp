// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// Date-> 11/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool cmp(Job &val1, Job &val2){
    return val1.profit > val2.profit;
}

class Solution 
{
    
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, cmp);
        
        int maxDead = -1;
        for(int i=0; i<n; i++){
            maxDead = max(maxDead, arr[i].dead);
        }
        
        vector<int> jobOrd(n+1, -1);
        
        int cnt = 0;
        int maxProfit = 0;
        
        for(int i=0; i<n; i++){
            for(int j=arr[i].dead; j>0; j--){
                if(jobOrd[j] == -1){
                    cnt++;
                    maxProfit += arr[i].profit;
                    jobOrd[j]  = arr[i].id;
                    break;
                }
            }
        }
        
        return {cnt, maxProfit};
    } 
};