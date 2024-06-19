// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/magical-box5306/1

// Date-> 19/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxVolume(double perimeter, double area) {
        double peri = perimeter, a=area;
        double len = (peri/2-sqrt(peri*peri/4-6*a))/6;
        return len*len*(peri/4-2*len);
    }
};