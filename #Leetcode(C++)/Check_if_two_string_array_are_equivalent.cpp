// Question:-

// Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

// A string is represented by an array if the array elements concatenated in order forms the string.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        int one = 0;
        int second = 0;

        for(auto& a: word1)
            for(auto& x : a)
                if( second < word2[one].size())
                    {
                    if(x != word2[one][second++])
                        return false;
                    }   
                else if (++one < word2.size() )
                    {
                        second = 0;
                        if(x != word2[one][second++])
                            return false;
                    }
                else
                    return false;
                    
                
        return one == word2.size() - 1 && second == word2[one].size();
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    vector<string> word1;
    vector<string> word2;


    while(t--){
        int n;
        cout << "Enter the number of strings in word1: ";
        cin >> n;
        cout << "Enter the strings in word1: ";
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            word1.push_back(s);
        }

        cout << "Enter the number of strings in word2: ";
        cin >> n;
        cout << "Enter the strings in word2: ";
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            word2.push_back(s);
        }

        Solution obj;
        bool result = obj.arrayStringsAreEqual(word1, word2);
        if(result)
            cout << "The arrays represent the same string." << endl;
        else
            cout << "The arrays do not represent the same string." << endl;

        word1.clear();
        word2.clear();
    }

    return 0;

}