#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include <string>
#include <iostream>
#include <vector>

#include "student.h"

using namespace std;

class student_list
{
	private:
	vector<Student> students;

public:
	void addStudent(Student student) {
		students.push_back(student);
	}

	void addStudent(string lastName, string firstName) {
		Student student(lastName, lastName);
		students.push_back(student);
	}

	void printStudents() {
		for (int i = 0; i < students.size(); i++) {
			cout << "student name: " << students[i].getLastName() + ", " + students[i].getFirstName() << endl;
		}
	}

};

#endif

