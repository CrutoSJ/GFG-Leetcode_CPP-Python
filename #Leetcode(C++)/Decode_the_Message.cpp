// #Question:-

// You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:

// Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
// Align the substitution table with the regular English alphabet.
// Each letter in message is then substituted using the table.
// Spaces ' ' are transformed to themselves.
// For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').
// Return the decoded message.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> m;
        string ans = "";
        int i = 0;
        for(auto k : key){
            if(k != ' '){
                if(!m[k])
                    m[k] = 'a' + i++;
            }
        }
        for(auto msg : message){
            if(msg == ' ')
                ans += " ";
            else
                ans += m[msg];
        }
        return ans;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    
    while(t--){
        string key, message;
        cout << "Enter the key: ";
        cin.ignore();  
        getline(cin, key); 
        cout << "Enter the message: ";
        getline(cin, message); 
        
        Solution obj;
        string decodedMessage = obj.decodeMessage(key, message);
        cout << "Decoded message: " << decodedMessage << endl;
    }
    
    return 0;
}