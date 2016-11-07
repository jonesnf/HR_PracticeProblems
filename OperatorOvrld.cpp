#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <vector>
#include "main.h"
#include <cmath>
#include <algorithm>
using namespace std;

/***
Practice Problem : Operator Overload 
	SUMMARY: Given two matrices, add them together using operator overloading. 
	NOTES:
		- Make a Matrix class that holds a member "a" of type vector<vector<int>>
		- T => number of test cases
		- N , M => number or rows, columns respectively. 
		- Ai,j => values entering row by row
		- Make sure to use operator overload
***/


class Matrix {
	
public:
	vector<vector<int>> a;

};

Matrix operator+(Matrix x, Matrix y) {
	int i, j;

	for (i = 0; i < x.a.size(); i++) {
		for (j = 0; j < x.a[i].size(); j++) {
			x.a[i][j] = x.a[i][j] + y.a[i][j];
		}
	}
	return x;
}

int main() {
	int cases, k;
	cout << "Enter test cases: \n";
	cin >> cases;
	for (k = 0; k<cases; k++) {
		Matrix x;
		Matrix y;
		Matrix result;
		int n, m, i, j;
		cout << "Enter size of matrix (row wise): \n";
		cin >> n >> m;
		cout << "Get ready to enter " << m << " numbers for " << n << " rows...\n";
		for (i = 0; i<n; i++) {
			vector<int> b;
			int num;
			for (j = 0; j<m; j++) {
				cin >> num;
				b.push_back(num);
			}
			x.a.push_back(b);
		}
		cout << "Get ready to enter " << m << " numbers for " << n << " rows...\n";
		for (i = 0; i<n; i++) {
			vector<int> b;
			int num;
			for (j = 0; j<m; j++) {
				cin >> num;
				b.push_back(num);
			}
			y.a.push_back(b);
		}
		result = x + y;
		for (i = 0; i<n; i++) {
			for (j = 0; j<m; j++) {
				cout << result.a[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}