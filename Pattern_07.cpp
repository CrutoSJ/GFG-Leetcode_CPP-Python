#include<bits/stdc++.h>
using namespace std;

void print (int n){
    for(int i =0; i<n; i++){
        //This is for printing the spaces for 1st time.
        for(int j = 0; j<n-i+1; j++){
            cout << " ";
        }
        //This is for printing "*""
        for(int j =0; j<2*i+1; j++){
            cout << "*";
        }
        //This is for printing spaces for 2nd time.
        for(int j =0; j<n-i+1; j++){
            cout << " ";
        }

        cout << endl;
    }
}

int main(){
    int t;
    cin >> t;
    for (int i=0; i < t; i++){
        int n;
        cin >> n;
        print(n);
    }
}