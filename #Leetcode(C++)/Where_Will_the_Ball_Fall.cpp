#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> ans(col, -1);
        for (int j = 0; j < col; j++)
        {
            int ballPosition = j;
            int i = 0;
            while (i < row)
            {
                if (grid[i][ballPosition] == 1)
                {
                    if (ballPosition + 1 == col) break;
                    else if (grid[i][ballPosition + 1] == -1) break;
                    ballPosition++;
                }
                else
                {
                    if (ballPosition - 1 < 0) break; 
                    else if (grid[i][ballPosition - 1] == 1) break; 
                    ballPosition--;
                }
                i++;
            }
            if (i == row) ans[j] = ballPosition;
        }
        return ans;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n, m;
        cout << "Enter the number of rows and columns: ";
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));
        cout << "Enter the elements of the grid:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        Solution solution;
        vector<int> result = solution.findBall(grid);

        cout << "Resulting positions of the ball for each column: ";
        for (int i = 0; i < m; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;

}
