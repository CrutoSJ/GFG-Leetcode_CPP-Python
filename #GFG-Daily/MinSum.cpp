// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimum-sum4058/1

// Date-> 09/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution2 { // TC - O(n)
  private:
    string addStrings(string &s1, string &s2){
        int i = s1.length()-1;
        int j = s2.length()-1;
        int c = 0;
        string res = "";
        
        while(i >= 0 || j >= 0 || c > 0){
            int sum = c;
            
            if(i >= 0){
                sum += (s1[i] - '0');
            }
            
            if(j >= 0){
                sum += (s2[j] - '0');
            }
            
            i--, j--;
            res += (sum % 10 + '0');
            c   = sum/10; 
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
  public:
    string minSum(vector<int> &arr) {
        vector<int> freq(10, 0);
        
        for(auto &val : arr){
            freq[val]++;
        }
        
        string s1 = "";
        string s2 = "";
        bool flag = true;
        
        for(int digit=0; digit<10; digit++){
            while(freq[digit]--){
                if(flag){
                    if(!(s1.empty() && digit==0)){
                        s1.push_back(digit + '0');
                    }
                    flag = false;
                } else{
                    if(!(s2.empty() && digit==0)){
                        s2.push_back(digit + '0');
                    }
                    flag = true;
                }
            }
        }
        return addStrings(s1, s2);
    }
};

class Solution { // TC - O(n * log n)
  public:
    string minSum(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        string num1 = "" , num2 = "";
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                num1 += '0'+arr[i]; 
            } else{
                num2 += '0'+arr[i];
            }
        }
        
        string res = "";
        int s1 = num1.size(), s2 = num2.size();
        int i=s1-1, j=s2-1, carry=0;
        
        while(i>-1 || j>-1 || carry){
            int temp1 = i>-1 ? num1[i]-'0' : 0;
            int temp2 = j>-1 ? num2[j]-'0' : 0;
            int num = temp1+temp2+carry;
            res += '0'+num%10;
            carry = num/10;
            i--, j--;
        }
        reverse(res.begin(), res.end());
        int idx = 0;
        for(idx=0; idx<res.length(); idx++){
            if(res[idx] != '0'){
                break;
            }
        }
        return res.substr(idx);
    }
};