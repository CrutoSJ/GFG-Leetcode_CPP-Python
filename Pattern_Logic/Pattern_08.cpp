#include <bits/stdc++.h>
using namespace std;

void print(int n){
    for (int i=0; i<=n; i++){
        //first printing the spaces
        for (int j=0; j<i; j++){
            cout << " ";
        }
        //for printing the *
        for (int j=0; j<2*n- (2*i + 1); j++){
            cout << "*";
        }
        //for printing the spaces again
        for (int j=0; j<i; j++){
            cout << " ";
        }

        cout << endl;
    }
}

int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        int n;
        cin >> n;
        print(n);
    }
}