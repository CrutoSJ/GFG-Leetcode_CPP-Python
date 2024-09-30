// #Question:-

// Link-> https://leetcode.com/problems/design-a-stack-with-increment-operation/description/?envType=daily-question&envId=2024-09-30

// Date-> 30/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    vector<int> st;
    vector<int> inc;
    int n;

    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(st.size() < n){
            st.push_back(x);
            inc.push_back(0);
        }
    }
    
    int pop() {
        if(st.size() == 0){
            return -1;
        }

        int idx = st.size() - 1;
        if(idx > 0){
            inc[idx-1] += inc[idx];
        }

        int top_val = st[idx] + inc[idx];
        st.pop_back();
        inc.pop_back();

        return top_val;
    }
    
    void increment(int k, int val) {
        int idx = min(k, (int)st.size()) - 1;
        if(idx >= 0){
            inc[idx] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */