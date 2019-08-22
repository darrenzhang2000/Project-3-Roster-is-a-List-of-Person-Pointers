#include "Roster.hpp"
#include <string>

	/**
	default constructor for empty roster
	**/
Roster::Roster():List<Person*>(){	
}


	 /**parameterized constructor
	 @pre the input file is expected to be in CSV
	 (comma separated value) where each line has format:
	 “id,first_name_,last_name\n"
	 @param input_file_name the name of the input csv file
	 @post Student objects are added to roster as per the data
	 in the input file
	 **/
Roster::Roster(std::string input_file_name):List<Person*>(){	
	std::ifstream infile; 
	infile.open(input_file_name);
	int id_int;
	std::string id, first, last, person_type; //the variables to store the inputted data 
	while(getline(infile, id, ',')&&getline(infile, first, ',') && getline(infile, last, ',') && getline(infile, person_type)){ //comma is the delimiter
		id_int = std::stoi(id); // s to i converts the string id to integer id 
		if(person_type == "student"){
			Student* temp_s = new Student(id_int, first, last); // dynamically allocates student object and stores to student pointer
			double randomGpa = randGpa(); //generate random Gpa
			temp_s->setGpa(randomGpa); //set Gpa
			std::string randomMajor = randMajor(); // generate random Major
			temp_s->setMajor(randomMajor); //set Major
			
			Person* temp = temp_s; // store temp_s to a person pointer
			insert( item_count_ , temp); //adds person temp pointer to the list of pointers
 
			

		}
		else if(person_type == "teaching_assistant"){
			TeachingAssistant* temp_ta = new TeachingAssistant(id_int, first, last);  //dynamically allocates teaching_assistant object and store to teaching_assistant pointer
			ta_role randomRole = randRole();
			temp_ta->setRole(randomRole);
			
			Person* temp = temp_ta; //stores temp_ta in a person pointer
			insert( item_count_ , temp); //adds person pointer to the list of pointers

		}
		else{ 
			Instructor* temp_te = new Instructor(id_int, first, last); //dynamically allocates instructor to instructor pointer
			temp_te -> setContact("235Instructors@hunter.cuny.edu"); 
			temp_te -> setOffice("1000C");
			
			Person* temp = temp_te; //stores instructor pointer to a person pointer
			insert( item_count_ , temp); //adds person pointer to the list of pointers 

		}	 
	}
	
}

	/**@post displays all students in roster, one per line
	 in the form "first_name_ last_name_\n"
	 **/
void Roster::display(){
	for(int i=0; i< item_count_; i++){
		getItem(i)->display();
	}
}


	 /**
	@return a number randomly sampled from
	 {4.0, 3.75, 3.5, 3.25, 3.0, 2.75, 2.5, 2.25, 2.0}
	 */
double Roster::randGpa(){
	const int SIZE = 9;
	double arr[] =  {4.0, 3.75, 3.5, 3.25, 3.0, 2.75, 2.5, 2.25, 2.0};
	return arr[rand() % SIZE]; //random from array
}
	
	/**
	@return a string randomly sampled from
	 {"Computer Science", "Literature", "Music", "Philosophy", "Physics",
	"Theatre", "Computational Biology", "Mathematics", "Geography",
	"Linguistics"}
	 */
std::string Roster::randMajor(){
	const int SIZE = 10;
	std::string arr[] =  {"Computer Science", "Literature", "Music", "Philosophy", "Physics",
							"Theatre", "Computational Biology", "Mathematics", "Geography",
							"Linguistics"};
	return arr[rand() % SIZE]; //random from array 
}
	
	/**
	@return a ta_role randomly sampled from
	 {LAB_ASSISTANT, LECTURE_ASSISTANT,FULL_ASSISTANT}
	 */
ta_role Roster::randRole(){
	const int SIZE = 3;
	ta_role arr[]=  {LAB_ASSISTANT, LECTURE_ASSISTANT,FULL_ASSISTANT};
	return arr[rand() % SIZE];	//random enum from array (either 0, 1 or 2)
}
		 
		 
		 
		 
		 