#include <iostream>
using namespace std;


/*
PROBLEM: Variable Sized Arrays
	BRIEF: create and array with variable sized arrays in it based on inputs and be able to answer queries that request certain indexes
	INPUT:  
		- First line: two seperated integers that determine N (size of array) &  Q (number of queries)
		- Secnd line: K (number of elements in array), a[0]... a[k-1]
		- Third line: Queries starting with i (index of main array) , j (index of array with index i of main array)

*/
int main() {

	int size, queries, lilArraySize, i, j, maIndex, laIndex, val;  // maIndex = Main Array Index, laIndex = lil Array Index
	cout << "Enter size of main array and num of queries: ";
	cin >> size >> queries;
	int **mainArray = new int*[size];

	for (j = 0; j < size; j++) {
		cout << "Enter size of embedded array: ";
		cin >> lilArraySize;

		int *tempArray = new int[lilArraySize];
		mainArray[j] = tempArray;
		for (i = 0; i < lilArraySize; i++) {
			cout << "Enter value for index " << i << " : ";
			cin >> tempArray[i];
		}
	}

	for (i = 0; i < queries; i++) {
		cout << "Enter indexes for value in \" int int \" format: ";
		cin >> maIndex;
		cin >> laIndex;

		cout << mainArray[maIndex][laIndex] << "\n";

	}

	delete mainArray;
	
	return 0;
}