// Question:-

// A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.

// A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

// For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
// Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string sortSentence(string s) {
        vector<string> pos(10,""); 
        for(int i=0; i<s.size(); i++){
            string temp; 
            while(!isdigit(s[i])) 
                temp += s[i++]; 
            pos[s[i++]-'0'] = temp; 
        }
        string ans;
        for(int i=1; i<10; i++){
            if(pos[i].length()>0)
                ans += pos[i] + ' ';
        }
        ans.pop_back();
        return ans;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    cin.ignore();
    Solution solution;
    while(t--){
        string s;
        cout << "Enter the shuffled sentence: ";
        getline(cin, s);

        string originalSentence = solution.sortSentence(s);
        cout << "Reconstructed sentence: " << originalSentence << endl;
    }
    return 0;

}