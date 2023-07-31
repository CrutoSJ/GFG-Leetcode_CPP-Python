/* The given question is asking for the minimum number of minutes needed to pick up all the garbage in
the city. */
// #Question:-

// You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house. garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively. Picking up one unit of any type of garbage takes 1 minute.

// You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.

// There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.

// Only one garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks cannot do anything.

// Return the minimum number of minutes needed to pick up all the garbage.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int>prefix;
            prefix.push_back(travel[0]);
            for(int i=1;i<travel.size();i++)
            {
                prefix.push_back(prefix[i-1]+travel[i]);
            }
            
            int metal = INT_MIN;
            int glass = INT_MIN;
            int paper = INT_MIN;

            vector<unordered_map<char,int>>v(garbage.size());

            for(int i=0;i<garbage.size();i++)
            {
                string str = garbage[i];
                for(int j=0;j<str.length();j++)
                {
                    if(str[j] == 'G') glass = max(glass,i);
                    else if(str[j] == 'M') metal = max(metal,i);
                    else if(str[j] == 'P') paper = max(paper ,i);

                    v[i][str[j]]++;
                }
            }
            int time = 0;

            if(glass == 0)
            {
                time = time + v[0]['G'];
            }
            else if(glass > 0)
            {
                time = time + prefix[glass-1];
                for(int i=0;i<=glass;i++)
                {
                    time = time + v[i]['G'];
                }
            }
            
            if(paper == 0)
            {
                time = time + v[0]['P'];
            }
            else if(paper > 0)
            {
                time = time + prefix[paper-1];
                for(int i=0;i<=paper;i++)
                {
                    time = time + v[i]['P'];
                }
            }

            if(metal == 0)
            {
                time = time + v[0]['M'];
            }
            else if(metal > 0)
            {
                time = time + prefix[metal-1];
                for(int i=0;i<=metal;i++)
                {
                    time = time + v[i]['M'];
                }
            }

            return time;
                
        }
};

int main() {
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter the number of houses: ";
        cin >> n;

        vector<string> garbage(n);
        cout << "Enter garbage assortments for each house (M, P, G only): " << endl;
        for (int i = 0; i < n; i++) {
            cin >> garbage[i];
        }

        vector<int> travel(n - 1);
        cout << "Enter travel times between houses: " << endl;
        for (int i = 0; i < n - 1; i++) {
            cin >> travel[i];
        }

        Solution sol;
        int result = sol.garbageCollection(garbage, travel);
        cout << "Minimum number of minutes needed to pick up all the garbage: " << result << endl;
    }

    return 0;
}