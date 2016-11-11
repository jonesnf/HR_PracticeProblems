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
This problem is to get you familiar with virtual functions. Create three classes Person, Professor and Student. 
The class Person should have data members name and age. The classes Professor and Student should inherit from the class Person.

The class Professor should have two data members: publications and cur_{id}. There will be two member functions: getdata and putdata. 
The function getdata should get the input from the user: the name, age and publications of the professor.
The function putdata should print the name, age, publications and the cur_{id} of the professor.

The class Student should have two data members: marks, which is an array of size  and cur_{id}. 
It has two member functions: getdata and putdata. 
The function getdata should get the input from the user: the name, age, and the marks of the student in  subjects. 
The function putdata should print the name, age, sum of the marks and the cur_{id} of the student.

For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from .

Solve this problem using virtual functions, constructors and static variables. You can create more data members if you want.

Input Format

There are two types of input. If the object being created is of the Professor class, you will have to input the name, age and publications of the professor.

If the object is of the Student class, you will have to input the name, age and the marks of the student in  subjects.

Constraints


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