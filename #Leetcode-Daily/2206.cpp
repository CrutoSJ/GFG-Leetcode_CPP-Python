// #Question:-

// Link-> https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=daily-question&envId=2025-03-17

// Date-> 17/03/25

// #Solution:-

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_set<int> st;
            for(int &i:nums){
                if(st.count(i)){
                    st.erase(i);
                } else{
                    st.insert(i);
                }
            }
            return st.empty();
        }
    };