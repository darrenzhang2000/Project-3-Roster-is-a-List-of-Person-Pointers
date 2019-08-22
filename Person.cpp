#include "Person.hpp"
#include <string>

Person::Person(){
	id_ = 0;
	first_name_ = "";
	last_name_ = "";
}


	//@param id unique id of person
	//@param first firstname of person	
	//@param last lastname of person object 
	//@pre id>0
	//@post creates an instance of a person object 
	//constructor
Person::Person(int id, std::string first, std::string last){
	id_ = id;
	first_name_ = first;
	last_name_ = last;
}

	//accessor - returns ID
	//@pre none
	//@post return value of ID 
	//@return the value of ID
int Person::getID() const{
	return id_;
}

	//accessor - returns first name
	//@pre none
	//@post return value of firstname
	//@return firstname of person object
std::string Person::getFirstName() const{
	return first_name_;
}


	//accessor - returns last name
	//@pre none
	//@post return value of lastname
	//@return lastname of person object
std::string Person::getLastName() const{
	return last_name_;
}


