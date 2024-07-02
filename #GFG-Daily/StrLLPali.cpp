// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1

// Date -> 02/07/24

// #Solution:-


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
private:
    bool isPali(string s){
        int i=0, j=s.size()-1;
        while(j>=i){
            if(s[i]!=s[j]) return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
public:
    bool compute(Node* head) {
        string ans = "";
        Node* temp = head;
        while(temp!=NULL){
            ans +=temp->data;
            temp=temp->next;
        }
        return isPali(ans);
    }
};