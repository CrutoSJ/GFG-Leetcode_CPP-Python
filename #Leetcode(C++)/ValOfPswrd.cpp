#include<bits/stdc++.h>
using namespace std;

bool isValid(string &str)
{
	// Write your code here.
	if(str.length() < 8 || str.length() > 15){
		return false; 
	}

	bool hasDigit = false;
	bool hasLower = false;
	bool hasUpper = false;
	bool hasSpecial = false;

	for(char c : str){

		if(isspace(c))
			return false;

		if(isdigit(c))
			hasDigit = true;

		else if (isupper(c))
			hasUpper = true;

		else if (islower(c))
			hasLower = true;

		else if (ispunct(c))
			hasSpecial = true;

	}

	return hasDigit && hasLower && hasUpper && hasSpecial;
}
