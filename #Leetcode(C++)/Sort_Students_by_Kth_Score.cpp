// Question:-

// There is a class with m students and n exams. You are given a 0-indexed m x n integer matrix score, where each row represents one student and score[i][j] denotes the score the ith student got in the jth exam. The matrix score contains distinct integers only.

// You are also given an integer k. Sort the students (i.e., the rows of the matrix) by their scores in the kth (0-indexed) exam from the highest to the lowest.

// Return the matrix after sorting it.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(),score.end(),[&](vector<int>  &first,vector<int> &second){
            return first[k]>second[k];
        });
        return score;
    }
};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t--){
        int m, n, k;
        cout << "Enter the number of students (m): ";
        cin >> m;
        cout << "Enter the number of exams (n): ";
        cin >> n;

        vector<vector<int>> score(m, vector<int>(n));

        cout << "Enter the scores matrix: ";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> score[i][j];
            }
        }

        cout << "Enter the value of k: ";
        cin >> k;

        Solution obj;
        vector<vector<int>> sortedScore = obj.sortTheStudents(score, k);

        cout << "Sorted matrix: ";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << sortedScore[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;



}