// Question:-

// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void Sum(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& r, int i)
    {
        
        if(target == 0)
        {
            res.push_back(r);
            return;
        }
        
        while(i <  candidates.size() && target - candidates[i] >= 0)
        {
            r.push_back(candidates[i]);
            
            Sum(candidates,target - candidates[i],res,r,i);
            ++i;
            
            r.pop_back();
        }
}
    
     
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        
        vector<int> r;
        vector<vector<int> > res;
        
        Sum(candidates,target,res,r,0);
        
        return res;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;

        vector<int> candidates(n);
        cout << "Enter the elements: ";
        for(int i = 0; i < n; i++){
            cin >> candidates[i];
        }

        int target;
        cout << "Enter the target sum: ";
        cin >> target;

        Solution obj;
        vector<vector<int>> combinations = obj.combinationSum(candidates, target);

        cout << "Unique combinations that sum up to " << target << " are:\n";
        for(auto combination : combinations){
            cout << "[ ";
            for(int num : combination){
                cout << num << " ";
            }
            cout << "]\n";
        }
    }

    return 0;

}