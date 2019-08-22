#include "Student.hpp"
#include "Person.hpp"
#include <string>

//default constructor for student
Student::Student():Person(){
	major_ = ""; 
	gpa_ = 0;
}


	//@pre id>0
	//@post none
	//constructor
Student::Student(int id, std::string first, std::string last):Person(id, first, last){
	major_ = "";
	gpa_ = 0;
}

	//accessor- returns major_
	//@pre none
	//@post none
	//@return the student's major
std::string Student::getMajor() const{
	return major_;
}

	//@pre none
	//@post none
	//accessor- returns gpa_
	//@return the student's gpa
double Student::getGpa() const{
	return gpa_;
}

	//mutator- sets major_ to major
	//@param major the student's major
	//@pre a string
	//@post changes the student's major
void Student::setMajor(const std::string major){
	major_ = major;
}

	//mutator- sets gpa_ to gpa
	//@param gpa- the student's gpa
	//@ore greater than 0, less than or equal to 4.0
void Student::setGpa(const double gpa){
	gpa_ = gpa;
}

	//accessor
	//@post prints first name, last name , major and gpa
void Student::display() {
	std::cout << first_name_ << " " << last_name_ << " majors in " << major_ << " with gpa: " << gpa_ << std::endl;	
}

	