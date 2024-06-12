// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/count-numbers-containing-43022/1

// Date-> 12/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNumberswith4(int n) {
        int count=0;
        for(int i=0; i<=n; i++){
            string ch = to_string(i);
            for(int j=0; j<ch.length(); j++){
                if(ch[j] == '4'){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};