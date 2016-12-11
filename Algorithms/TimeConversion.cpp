#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

/*

	HR->Algorithm->Warmup->Time Converter
	PROBLEM: Make a 24H time converter.
		INPUT: Given input will come in form of HH:MM:SS(PM/AM)
		OUTPUT: Print out the time in 24h format!


*/

int main(){
	
	int h, m, s;
	char c[3];

	cout << "Enter time in hh:mm:ssPM/AM format: ";
	
	scanf_s("%d:%d:%d%2c", &h, &m, &s, c); //had to add the %2c in able to store it in char array.  2 is the width I defined that scanf will read 
	
	(c[0] == 'P' && h != 12) ? h += 12 : (h == 12 && c[0] == 'A') ? h = 0 : h = h;
	
	printf("%02d:%02d:%02d", h, m, s);

	
	return 0;
}