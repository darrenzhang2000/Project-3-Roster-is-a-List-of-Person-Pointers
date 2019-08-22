#ifndef _ROSTER_
#define _ROSTER_
#include <fstream>
#include "Student.hpp"
#include "Person.hpp"
#include <ctime>
#include "List.hpp"
#include "TeachingAssistant.hpp"
#include "Instructor.hpp"
//srand(static_cast<unsigned>(time(0)));

class Roster:public List<Person*>{
public:
	/**
	default constructor for empty roster
	**/
	Roster(); 
	
	 /**parameterized constructor
	 @pre the input file is expected to be in CSV
	 (comma separated value) where each line has format:
	 “id,first_name_,last_name\n"
	 @param input_file_name the name of the input csv file
	 @post Student objects are added to roster as per the data
	 in the input file
	 **/
	 Roster(std::string input_file_name);	
		
	/**@post displays all students in roster, one per line
	 in the form "first_name_ last_name_\n"
	 **/
	 void display(); 	
	 
	 /**
	@return a number randomly sampled from
	 {4.0, 3.75, 3.5, 3.25, 3.0, 2.75, 2.5, 2.25, 2.0}
	 */
	double randGpa();
	
	/**
	@return a string randomly sampled from
	 {"Computer Science", "Literature", "Music", "Philosophy", "Physics",
	"Theatre", "Computational Biology", "Mathematics", "Geography",
	"Linguistics"}
	 */
	std::string randMajor();
	
	/**
	@return a ta_role randomly sampled from
	 {LAB_ASSISTANT, LECTURE_ASSISTANT,FULL_ASSISTANT}
	 */
	ta_role randRole(); 
		 
};

#endif 