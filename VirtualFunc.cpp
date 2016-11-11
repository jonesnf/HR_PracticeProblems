#include "stdio.h"
#include "stdlib.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
PROBLEM: Virtual Functions
	BRIEF: Create a Student and Professor class that inherits from a Person abstract class.
		   Collect data about the student/professor, and print the results.
	INPUT:
		- How many people
		- Enter 1 for Student, 2 for professor
			- if 1, add name, age, 6 test scores, and assign studentID that's unique for each - incrementing by 1
			- if 2, add name, age, # of publications, and unique professorID that increments by 1
	OUTPUT:
		- Print each person and all their data
			- for students add up all test scores and print sum

*/

class Person {

protected:
	int age;
	string name;
public:
	virtual void putdata()=0;
	virtual void getdata()=0;

};

int g_profID = 0;
class Professor : public Person {

private: 
	int publications, currentID = 0;
public:
	Professor() { 
		g_profID++;
	}
	void getdata() {
		cout << "Enter Name: \n";
		cin >> name;
		cout << "Enter Age: \n";
		cin >> age;
		cout << "Enter Num of Publications: \n";
		cin >> publications;
		currentID = g_profID;
		
	}
	void putdata() { cout << name << " " << age << " " << publications << " " << currentID << "\n"; }
	

};


int g_stuID = 0;
class Student : public Person {

private: 
	int marks[6], i, total = 0, currentID = 0;
public:
	Student() {
		g_stuID++;
	}
	void getdata() {
		cout << "Enter Name: \n";
		cin >> name;
		cout << "Enter Age: \n";
		cin >> age;
		for (i = 0; i < sizeof(marks) / sizeof(int); i++) {
			cout << "Enter test score " << i << ": ";
			cin >> marks[i];
			total += marks[i];
		}
		currentID = g_stuID;
	}
	void putdata() { cout << name << " " << age << " " << total << " " << currentID << "\n"; }

};

int main() {

		int n, val;
		cout << "Enter number of people: ";
		cin >> n; //The number of objects that is going to be created.
		Person **per = new Person*[n];

		for (int i = 0; i < n; i++) {

			cout << "Enter 1 for Professor or 2 for student: ";
			cin >> val;
			if (val == 1) {
				// If val is 1 current object is of type Professor
				per[i] = new Professor;

			}
			else per[i] = new Student; // Else the current object is of type Student

			per[i]->getdata(); // Get the data from the user.

		}

		for (int i = 0; i<n; i++)
			per[i]->putdata(); // Print the required output for each object.

		return 0;

}