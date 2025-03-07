// #Question:-

// Link -> https://leetcode.com/problems/closest-prime-numbers-in-range/?envType=daily-question&envId=2025-03-07

// Date -> 07/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            int upperLimit = right;
            vector<int> sieveArray = sieve(upperLimit);
    
            vector<int>
                primeNumbers; 
            for (int num = left; num <= right; num++) {
                if (sieveArray[num] == 1) {
                    primeNumbers.push_back(num);
                }
            }
    
            if (primeNumbers.size() < 2)
                return vector<int>{-1, -1};
    
            int minDifference = INT_MAX;
            vector<int> closestPair(2, -1); 
    
            for (int index = 1; index < primeNumbers.size(); index++) {
                int difference = primeNumbers[index] - primeNumbers[index - 1];
                if (difference < minDifference) {
                    minDifference = difference;
                    closestPair[0] = primeNumbers[index - 1];
                    closestPair[1] = primeNumbers[index];
                }
            }
    
            return closestPair;
        }
    
    private:
        vector<int> sieve(int upperLimit) {
            vector<int> sieve(upperLimit + 1,1);  
            sieve[0] = 0;
            sieve[1] = 0;
    
            for (int number = 2; number * number <= upperLimit; number++) {
                if (sieve[number] == 1) {
                    for (int multiple = number * number; multiple <= upperLimit; multiple += number) {
                        sieve[multiple] = 0;
                    }
                }
            }
            return sieve;
        }
    };