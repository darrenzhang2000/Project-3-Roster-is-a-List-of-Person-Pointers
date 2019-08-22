#ifndef _INSTRUCTOR_
#define _INSTRUCTOR_
#include "Person.hpp"
#include <string>

class Instructor:public Person{
public:
	//default constructor 
	Instructor();
	
	//constructor
	//@param id the id of the instructor
	//@param first the first name of the instructor
	//@param last the last name of the instructor
	Instructor(int id, std::string first, std::string last);
	
	//accessor  
	//@return the name/room number of the office
	std::string getOffice() const;
	
	//accessor 
	//@return the contact info of the instructor
	std::string getContact() const;
	
	//mutator changes room number
	//@param office the office of the instructor
	//@pre has to be a valid office
	void setOffice(const std::string office);
	
	//mutator changes contact info 
	//@param contact the contact info of the instructor
	//@pre has to be a valid contact (usually phone number or email)
	void setContact(const std::string contact);
	
	//accessor
	//@post prints instructor first name, last name, office and email
	void display() override;
private:
	std::string office_;
	std::string contact_;
};


#endif