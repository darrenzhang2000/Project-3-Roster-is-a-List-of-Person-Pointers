#include "Person.hpp"
#include "Student.hpp"
#include "TeachingAssistant.hpp"
#include "Instructor.hpp"
#include "Roster.hpp"

int main(){	
		/*
		Student darren = Student(0, "Darren", "Zhang");
		TeachingAssistant bob = TeachingAssistant(1, "bob", "bob2");
		Instructor Lig = Instructor(2, "lig", "1");
		//darren.display();
		//bob.display();
		Lig.display();
		*/
		Roster x("data_full.csv");
		x.display();
}