/*Final Project
Maddie Palmer
James McCracken
Aaron Longchamp
Connor Allan*/

#include "votey.h"
#include "graphics.h"

//constructor
Professor::Professor() { 
	name = "Lisa Dion"; 
	type = "C++"; 
	response = "Polymorphism!"; 
}

Professor::Professor(string n, string t, string r) { 
	setName(n); 	
	setType(t); 	
	setResponse(r); 
} 

//destructor
Professor::~Professor() { 
} 

//getters 
string Professor::getName() const { 
	return name; 
}

string Professor::getType() const { 
	return type;
}

string Professor::getResponse() const { 	
	return response; 
} 

//setters 
void Professor::setName(string nIn) { 
	name = nIn; 
} 

void Professor::setType(string tIn) { 
	type = tIn; 
} 

void Professor::setResponse(string rIn) { 
	response = rIn; 
}

//overloaded operator
ostream& operator << (ostream& outs, const Professor &p) {
	outs << "Name: " << p.name << endl << "Type: " << p.type << endl << "Response: " << p.response << endl; 
	return outs;
}

//overloading the == operator to see if two professors are equal based off of their names
bool operator == (const Professor &lhs, const Professor &rhs) { 
	return lhs.name == rhs.name; 
}

/*Person Class*********************************************/
//default constructor 
Person::Person() {
	name = " ";
}

//constructor
Person::Person(string n) { 	
	setName(n);
}

//destructor 
Person::~Person() { 
} 

//getters
string Person::getName() const { 
	return name; 
}

//setters 
void Person::setName(string nIn) { 
	name = nIn; 
} 

/*Trainer Class******************************************/
//constructor
Trainer::Trainer() { 
	professorBag.push_back(Professor()); 	
	professorBag.push_back(Professor("Jackie Horton", "Java", "Don't use semi-colons!")); 
	professorBag.push_back(Professor("Bob Erickson", "Web Design", "42")); 
	professorBag.push_back(Professor("Byung Lee", "Algorithms", "Use Dijkstra's Algorithm!"));
	professorBag.push_back(Professor("Alan Ling", "Cryptography", "Take the multiplicative inverse of e mod n!")); 
	score = 0; 
} 

//destructor 
Trainer::~Trainer() { 
} 

/*
//setters
void Trainer::setProfessor(const Professor &p) { 
professorBag[0] = p;
}
*/ 

int Trainer::getScore() { 
	return score;
}

//overloaded operator 
ostream& operator << (ostream& outs, const Trainer & t) { 	
	outs << "Name: " << t.getName() << endl; 
	outs << "Professors in Bag: " << endl; 
	for (int i = 0; i < (int)(t.professorBag.size()); ++i) { 
		outs << t.professorBag[i] << endl; 	} 
	return outs; 
} 

//addProfessor method 
void Trainer::addProfessor(Professor p) { 
	professorBag.push_back(p); 
}

//removeProfessor method 
void Trainer::removeProfessor(Professor p) { 
	for (int i = 0; i < professorBag.size(); ++i) { 
		if (p == professorBag[i]) { 		
			professorBag.erase(professorBag.begin() + i); 	
		} 
	}
} 

//Talk() method to be overrided 
string Trainer::Talk(int index, Student &s) { 
	if (professorBag[index].getType() == s.getQuestionType()) { 
		score += 1; 	
		return (professorBag[index].getResponse() + "\nYou got the question right!"); 		
	} 
	else
	{ 	
		return (professorBag[index].getResponse() + "\nYou got the question wrong :( you used the incorrect professor"); 
	} 
} 

/*Student Class***********************************/
Student::Student() { 
	question = "Can you summarize Computer Science in one sentence?";
	questionType = "misc";
}

Student::Student(string q, string qt) { 
	setQuestion(q); 
	setQuestionType(qt); 
} 

Student::~Student() { } 

//getters and setters 
string Student::getQuestion() const { 
	return question; 
}

string Student::getQuestionType() const { 
	return questionType; 
}

void Student::setQuestion(string qIn) { 
	question = qIn; 
} 

void Student::setQuestionType(string qtIn) { 
	questionType = qtIn;
} 

void Student::setAnswered() {
	answered = 1;
}

bool Student::getAnswered() {
	return answered;
}

//overloaded operator 
ostream& operator << (ostream& outs, const Student & s) { 	
	outs << "Name: " << s.getName() << endl; 
	outs << "Question: " << s.getQuestion() << endl; 	
	outs << "Question Type: " << s.getQuestionType() << endl; 
	return outs; 
} 

//Talk() method to be overrided 
string Student::Talk(int index, Student &s) { 	
	return question; 
} 

/*Square Class*************************************************/

Square::Square() { 
} 

Square::Square(int x, int y) { 
	xcoord = x; 	
	ycoord = y; 
}

void Square::setXCoord(int x) { 
	xcoord = x;
}

void Square::setYCoord(int y) {
	ycoord = y; 
} 

int Square::getXCoord() { 
	return xcoord; 
} 

int Square::getYCoord() { 
	return ycoord; 
} 