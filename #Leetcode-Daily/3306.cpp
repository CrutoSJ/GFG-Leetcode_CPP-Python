// #Question:-

// Link -> https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/?envType=daily-question&envId=2025-03-10

// Date -> 10/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isVowel(char &ch){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                return true;
            }
            return false;
        }
        long long countOfSubstrings(string word, int k) {
            int n=word.length();
            unordered_map<char,int> mp;
            int lCons=n;
            vector<int> nxtCons(n);
    
            for(int i=n-1; i>=0; i--){
                nxtCons[i]=lCons;
                if(!isVowel(word[i])){
                    lCons=i;
                }
            }
    
            long long resCnt = 0;
            int i=0, j=0;
            int consCnt=0;
    
            while(j<n){
                char ch=word[j];
    
                if(isVowel(ch)){
                    mp[ch]++;
                } else{
                    consCnt++;
                }
    
                while(i<n && consCnt>k){
                    char ch=word[i];
                    if(isVowel(ch)){
                        mp[ch]--;
                        if(mp[ch]==0){
                            mp.erase(ch);
                        }
                    } else{
                        consCnt--;
                    }
                    i++;
                }
    
                while(i<n && mp.size()==5 && consCnt==k){
                    int idx=nxtCons[j];
                    resCnt+=idx-j;
                    char ch=word[i];
    
                    if(isVowel(ch)){
                        mp[ch]--;
                        if(mp[ch]==0){
                            mp.erase(ch);
                        }
                    } else{
                        consCnt--;
                    }
                    i++;
                }
                j++;
            }
            return resCnt;
        }
    };