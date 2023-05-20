#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool prime(int x){
        if (x < 2)
            return false;
            
        for(int i = 2; i*i <= x; i++){
            if(x % i == 0){
                return false;
            }
        }
        
        return true;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cout << "Enter x: ";
        cin >> x;

        Solution a;
        auto Ans = a.prime(x);
        cout << Ans << endl;

    }
    return{};
}
