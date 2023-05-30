// Question:-

// There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.
// Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.
// Note that multiple kids can have the greatest number of candies.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies){
        int n = candies.size();
        int max = 0;
        vector<bool> result(n);
        for (int i = 0; i < n; i++) {
            if (candies[i] > max) {
                max = candies[i];
            }
        }
        for (int i=0; i<n; i++){ 
            int total =  candies[i] + extraCandies;
            if (total >= max) {
                result[i] = true;
            } else {
                result[i] = false;
            }
        }
        return result;
    }

};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    while(t--){
        int n;
        cout <<"Enter the size of array: ";
        cin >> n;

        cout << "Enter array elements: ";

        vector<int> candies(n);

        for(int i=0; i<n; i++){
            cin >> candies[i];
        }

        int extraCandies;
        cout << "Enter extraCandies: ";
        cin >> extraCandies;

        Solution solution;
        auto a = solution.kidsWithCandies(candies, extraCandies);

        for(int i=0; i<n; i++){
            cout << a[i] << " ";
        }

        cout << endl;

    }

}