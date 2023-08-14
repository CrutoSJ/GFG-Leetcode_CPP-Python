// #Question:-

// Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.

// A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

// Note that points on the edge of a vertical area are not considered included in the area.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
		int ans=0;
		sort(points.begin(),points.end());
		for(int i=0;i<points.size()-1;i++) ans=max(ans,points[i+1][0]-points[i][0]);
		return ans;
	}
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the number of points: ";
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        cout << "Enter the points (x, y): " << endl;
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution solution;
        int maxWidth = solution.maxWidthOfVerticalArea(points);
        cout << "Max Width of Vertical Area: " << maxWidth << endl;
    }
    return 0;

}