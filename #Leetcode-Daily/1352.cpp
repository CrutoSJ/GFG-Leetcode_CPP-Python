// #Question:-

// Link-> https://leetcode.com/problems/product-of-the-last-k-numbers/?envType=daily-question&envId=2025-02-14

// Date-> 14/02/25

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