// #Question:-

// Link-> https://leetcode.com/problems/all-oone-data-structure/description/?envType=daily-question&envId=2024-09-29

// Date-> 29/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class AllOne {
public:
    struct Node{
        int count;
        unordered_map<string, bool> keys;
        Node* prev;
        Node* next;
        Node(int c){
            count = c;
            prev = NULL;
            next = NULL;

        }
    };

    unordered_map<string, Node*> mp;
    Node* head;
    Node* tail;

    void addNode(Node* prevNode, int count){
        Node* newNode = new Node(count);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if(newNode->next != NULL){
            newNode->next->prev = newNode;
        }

        prevNode->next = newNode;
        if(prevNode == tail){
            tail = newNode;
        }
    }

    void removeNode(Node* node){
        node->prev->next = node->next;
        if(node->next != NULL){
            node->next->prev = node->prev;
        }

        if(tail == node){
            tail = node->prev;
        }

        delete node;
    }

    AllOne() {
        head = new Node(0);
        tail = head;
    }
    
    void inc(string key) {
        if(mp.find(key) == mp.end()){
            if(head->next == NULL || head->next->count != 1){
                addNode(head, 1);
            }

            head->next->keys[key] = true;
            mp[key] = (head->next);
        } else{
            Node* currNode = mp[key];
            int currCount  = currNode->count;
            if(currNode->next == NULL || currNode->next->count != currCount+1){
                addNode(currNode, currCount+1);
            }

            currNode->next->keys[key] = true;
            mp[key] = currNode->next;
            currNode->keys.erase(key);
            if(currNode->keys.empty()){
                removeNode(currNode);
            }
        }
    }
    
    void dec(string key) {
        Node* currNode = mp[key];
        int currCount = currNode->count;

        if(currCount == 1){
            mp.erase(key);
        } else{
            if(currNode->prev->count != currCount-1){
                addNode(currNode->prev, currCount-1);
            }
            currNode->prev->keys[key] = true;
            mp[key] = currNode->prev;
        }

        currNode->keys.erase(key);
        if(currNode->keys.empty()){
            removeNode(currNode);
        }
    }
    
    string getMaxKey() {
        if(tail == head){
            return "";
        }

        auto it = tail->keys.begin();
        return it->first;
    }
    
    string getMinKey() {
        if(head->next == NULL){
            return "";
        }

        auto it = head->next->keys.begin();
        return it->first;
    }
};