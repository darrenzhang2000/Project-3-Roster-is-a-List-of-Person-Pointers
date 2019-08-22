#ifndef _TEACHING_ASSISSTANT_
#define _TEACHING_ASSISSTANT_
#include "Student.hpp"
#include <iostream>

enum ta_role{LAB_ASSISTANT, LECTURE_ASSISTANT, FULL_ASSISTANT};

class TeachingAssistant:public Student{
public:
	//default constructor
	TeachingAssistant();
	
	//constructor
	//@param first the first name of the teachingasssistant object
	//@param last the last name of the teacing assistant object
	TeachingAssistant(int id, std::string first, std::string last);
	
	//accessor - return number of hours
	//@return the number of hours
	int getHours() const;
	
	//accessor - return role (either lab,lecture,or full assistant)
	//@return the role of the TA (one of lab assistant, lecture assistant or full assistant)
	ta_role getRole() const;
	
	//mutator - set number of hours
	//@param hours the number of hours
	void setHours(const int hours);
	
	//mutator - set role
	//@param role the role of the TA (one of lab assistant, lecture assistant or full assistant)
	void setRole(const ta_role role);
	
	//accessor 
	//@post prints first name, last name, major, gpa, and role
	void display() override;
private:
	//private data members
	int hours_per_week_;
	ta_role role_;
};

#endif