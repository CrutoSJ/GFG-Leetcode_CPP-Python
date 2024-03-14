// #Question:-

// Link -> https://www.codingninjas.com/studio/problems/maximum-nesting-depth-of-the-parentheses_8144741

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
	int count = 0;
	int ans=0;

	for(int i=0; i<s.length(); i++){
		if(s[i] == '('){
			count++;
			ans = max(ans,count);
		}

		if(s[i] == ')'){
			count--;
		}

	}

	return ans;
}
