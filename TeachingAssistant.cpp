#include "TeachingAssistant.hpp"

	//default constructor
TeachingAssistant::TeachingAssistant():Student(){
	hours_per_week_ = 0;
	role_ = LAB_ASSISTANT;
}

	//constructor
	//@param first the first name of the teachingasssistant object
	//@param last the last name of the teacing assistant object
TeachingAssistant::TeachingAssistant(int id, std::string first, std::string last):Student(id, first, last){
	hours_per_week_ = 0;
	role_ = LAB_ASSISTANT;
}


	//accessor - return number of hours
	//@return the number of hours
int TeachingAssistant::getHours() const{
	return hours_per_week_;
}

	//accessor - return role (either lab,lecture,or full assistant)
	//@return the role of the TA (one of lab assistant, lecture assistant or full assistant)
ta_role TeachingAssistant::getRole() const{
	return role_;	
}
	
	//mutator - set number of hours
	//@param hours the number of hours	
void TeachingAssistant::setHours(const int hours){
	hours_per_week_ = hours;
}


	//mutator - set role
	//@param role the role of the TA (one of lab assistant, lecture assistant or full assistant)
void TeachingAssistant::setRole(const ta_role role){
	role_ = role;
}


	//accessor 
	//@post prints first name, last name, major, gpa, and role
void TeachingAssistant::display(){
	
	std::cout << first_name_ << " " << last_name_ << " majors in " << major_ << " with gpa: " << gpa_ <<" working ";
	hours_per_week_ < 8? std::cout << "part-time": std::cout <<"full-time"; // if less than 8, part time, else full time
	std::cout << " as a ";
	if(role_ == 0){ 
		std::cout<< "LAB_ASSISTANT";
	}
	else if (role_ == 1){ 
		std::cout << "LECTURE_ASSISTANT";
	}
	else{
		std::cout << "FULL_ASSISTANT";
	}
	std::cout << std::endl;
}

