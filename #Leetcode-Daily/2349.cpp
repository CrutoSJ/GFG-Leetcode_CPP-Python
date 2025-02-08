// #Question:-

// Link-> https://leetcode.com/problems/design-a-number-container-system/description/?envType=daily-question&envId=2025-02-08

// Date-> 08/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class NumberContainers {
    public:
        NumberContainers() {}
    
        void change(int index, int number) {
            if (indexToNumbers.find(index) != indexToNumbers.end()) {
                int previousNumber = indexToNumbers[index];
                numberToIndices[previousNumber].erase(index);
                if (numberToIndices[previousNumber].empty()) {
                    numberToIndices.erase(previousNumber);
                }
            }
            indexToNumbers[index] = number;
            numberToIndices[number].insert(index);
        }
    
        int find(int number) {
            if (numberToIndices.find(number) != numberToIndices.end()) {
                return *numberToIndices[number].begin();
            }
            return -1;
        }
    
    private:
        unordered_map<int, set<int>> numberToIndices;
        unordered_map<int, int> indexToNumbers;
    };
    