#include <sstream>
#include <vector>
#include <iostream>
using namespace std;


/*
PROBLEM: String Stream
	BRIEF: Given a comma separated set of integers in a string, create a parse method that implements stringstream
    and print out just the integers
	INPUT:
		- Comma separated string of integers: e.g. 24,5,56
	OUTPUT:
		- Print each int on a new line
*/
vector<int> parseInts(string str) {
   vector<int> vec;
   int i, a, count;
   char ch;
    
   stringstream ss;
   ss << str; 
    
   for(i = 0; i < str.length(); i++){
       (str[i] == ',') ? count++ : count = count;
   }
    
   for(i = 0; i < count + 1; i++){
       ss >> a >> ch;
       vec.push_back(a);
   }
   
   return vec;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
