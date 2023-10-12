// #Question:-

// There is a stream of n (idKey, value) pairs arriving in an arbitrary order, where idKey is an integer between 1 and n and value is a string. No two pairs have the same id.

// Design a stream that returns the values in increasing order of their IDs by returning a chunk (list) of values after each insertion. The concatenation of all the chunks should result in a list of the sorted values.

// Implement the OrderedStream class:

// OrderedStream(int n) Constructs the stream to take n values.
// String[] insert(int idKey, String value) Inserts the pair (idKey, value) into the stream, then returns the largest possible chunk of currently inserted values that appear next in the order.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class OrderedStream{
    public:
    string dp[1005];
    int ptr;
    OrderedStream(int n){
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
    dp[idKey] = value;
        if(dp[ptr] != ""){
            vector<string> ans;
            for(int i=ptr;i<=1005;i++){
                if(dp[i] != ""){
                    ans.push_back(dp[i]);
                    ptr = i+1;
                }
                else
                {
                    break;
                }
            }
            return ans;
        }
        return {};
    }

};

int main(){
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter the number of values: ";
        cin >> n;

        OrderedStream os(n);

        while (true) {
            int id;
            string value;

            cout << "Enter idKey (1-" << n << ") and value (or type -1 to exit): ";
            cin >> id;

            if (id == -1)
                break;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, value);

            vector<string> chunk = os.insert(id, value);
            cout << "Chunk: ";
            for (const string& val : chunk) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    return 0;
}