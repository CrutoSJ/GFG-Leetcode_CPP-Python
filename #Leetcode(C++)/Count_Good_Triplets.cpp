// Question:-

// Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.

// A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

// 0 <= i < j < k < arr.length
// |arr[i] - arr[j]| <= a
// |arr[j] - arr[k]| <= b
// |arr[i] - arr[k]| <= c
// Where |x| denotes the absolute value of x.

// Return the number of good triplets.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (abs(arr[i] - arr[j]) <= a)
                {
                    for (int k = j + 1; k < arr.size(); k++)
                    {
                        int B = abs(arr[j] - arr[k]);
                        int C = abs(arr[k] - arr[i]);
                        if (B <= b and C <= c)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n, a, b, c;
        cout << "Enter the size of the array: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Enter the values of a, b, and c: ";
        cin >> a >> b >> c;

        Solution obj;
        int count = obj.countGoodTriplets(arr, a, b, c);
        cout << "Number of good triplets: " << count << endl;
    }

    return 0;

}