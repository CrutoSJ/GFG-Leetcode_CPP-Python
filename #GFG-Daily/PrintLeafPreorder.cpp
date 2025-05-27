// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1

// Date-> 27/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> leaf;
        stack<int> st;
        
        st.push(preorder[0]);
        
        for(int i=1; i<preorder.size(); i++){
            if(st.top()>preorder[i]){
                st.push(preorder[i]);
            } else{
                int cnt=0;
                int temp = st.top();
                while(!st.empty() && st.top()<preorder[i]){
                    st.pop();
                    cnt++;
                }
                st.push(preorder[i]);
                if(cnt>=2) leaf.push_back(temp);
            }
        }
        leaf.push_back(st.top());
        return leaf;
    }
};