// #Question:-

// Link-> https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/?envType=daily-question&envId=2025-02-13

// Date-> 13/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
    private:
        vector<int> prefixProduct;
        int size = 0;
    
    public:
        ProductOfNumbers() {
            prefixProduct.push_back(1);
            size = 0;
        }
    
        void add(int num) {
            if (num == 0) {
                prefixProduct = {1};
                size = 0;
            } else {
                prefixProduct.push_back(prefixProduct[size] * num);
                size++;
            }
        }
    
        int getProduct(int k) {
            if (k > size) return 0;
            return prefixProduct[size] / prefixProduct[size - k];
        }
};