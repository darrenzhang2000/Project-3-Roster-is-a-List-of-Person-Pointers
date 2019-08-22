#include "Instructor.hpp"

//default constructor 
Instructor::Instructor():Person(){
	office_ = "";
	contact_ =  "";
}


	//constructor
	//@param id the id of the instructor
	//@param first the first name of the instructor
	//@param last the last name of the instructor
Instructor::Instructor(int id, std::string first, std::string last):Person(id, first, last){
	office_ = "";
	contact_ = "";
}

	//accessor  
	//@return the name/room number of the office
std::string Instructor::getOffice() const{
	return office_;
}

	//accessor 
	//@return the contact info of the instructor
std::string Instructor::getContact() const{
	return contact_;
}

	
	//mutator changes room number
	//@param office the office of the instructor
	//@pre has to be a valid office
void Instructor::setOffice(const std::string office){
	office_ = office;
}

	//mutator changes contact info 
	//@param contact the contact info of the instructor
	//@pre has to be a valid contact (usually phone number or email)
void Instructor::setContact(const std::string contact){
	contact_ = contact;
}

	//accessor
	//@post prints instructor first name, last name, office and email
void Instructor::display(){
	std::cout << first_name_ << " " << last_name_ << " -  office: " <<   office_ << ", email:" << contact_ << std::endl;
}