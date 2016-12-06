#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/*
PROBLEM: Inherited Code
    BRIEF: Given an inputted username, check if the username is valid.  If too short, throw an exception
    INPUT: 
        - First line consists of how many test cases there are (T)
        - T number of lines containing usernames
    OUT: 
        - Valid, invalid, or exception

*/

class BadLengthException : public exception{
    
    public: 
        int tooShort;
        BadLengthException(int n){ tooShort = n; }
        int what(){ return tooShort; }
    
};

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}