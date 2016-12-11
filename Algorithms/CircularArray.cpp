#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


/*
	PROBLEM: Based on user input, rotate given array k-times and be able to query array after it's rotated
		INPUT: 
			- N, K, Q : Size of array, # of rotations, queries
			- i : elements of array (a[i])
			- q : query (new line for each )
		OUTPUT:
			- value at index q

*/

int main() {
	int n;
	int k;
	int q;
	int numRot;
	cout << "Enter N, K, Q: ";
	cin >> n >> k >> q;
	numRot = k%n;

	vector<int> a(n);
	cout << "Enter " << n << " numbers: ";
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
	}
	
	for (int a0 = 0; a0 < q; a0++) {

		int m;
		cout << "Enter index query: ";
		cin >> m;

		if (m - numRot >= 0) {
			cout << a[m - numRot] << endl;
		}
		else
			cout << a[m - numRot + a.size()] << endl;

	}

	return 0;
}