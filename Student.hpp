#ifndef _STUDENT_
#define _STUDENT_
#include "Person.hpp"
#include <string>

class Student:public Person{ //student is inherited class, person is base class
public:
	//default constructor for student
	Student();
	
	//@pre id>0
	//@post none
	//constructor
	Student(int id, std::string first, std::string last);
	
	//accessor- returns major_
	//@pre none
	//@post none
	//@return the student's major
	std::string getMajor() const;
	
	//@pre none
	//@post none
	//accessor- returns gpa_
	//@return the student's gpa
	double getGpa() const;
	
	//mutator- sets major_ to major
	//@param major the student's major
	//@pre a string
	//@post changes the student's major
	void setMajor(const std::string major);
	
	//mutator- sets gpa_ to gpa
	//@param gpa- the student's gpa
	//@pre greater than 0, less than or equal to 4.0
	void setGpa(const double gpa);
	
	//accessor
	//@post prints first name, last name , major and gpa
	virtual void display() override;
protected:
	//protected data mmbers- subclasses inherit these
	std::string major_;
	double gpa_;
};


#endif