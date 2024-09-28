// #Question:-

// Link-> https://leetcode.com/problems/design-circular-deque/?envType=daily-question&envId=2024-09-28

// Date-> 28/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    vector<int> dq;
    int front;
    int rear;
    int K;
    int currCnt;

    MyCircularDeque(int k) {
        K = k;
        dq = vector<int>(k,0);
        front = 0;
        rear = K-1;
        currCnt = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        front = (front - 1 + K) % K;
        dq[front] = value;
        currCnt++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        rear = (rear + 1) % K;
        dq[rear] = value;
        currCnt++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        front = (front + 1) % K;
        currCnt--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        rear = (rear - 1 + K) % K;
        currCnt--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return dq[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return dq[rear];
    }
    
    bool isEmpty() {
        return currCnt == 0;
    }
    
    bool isFull() {
        return currCnt == K;
    }
};