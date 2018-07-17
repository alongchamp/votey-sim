/*Final Project
  Maddie Palmer
  James McCracken
  Aaron Longchamp
  Connor Allan*/

#ifndef votey_h
#define votey_h
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Student;

class Professor {
public: 
	//default constructor 
	/** 	
	*Requires: nothing 
	*Modifies: name, response 	
	*Effects: sets default values for name("Lisa Dion"), and response("Polymorphism!") 	
	*/ 	
	Professor(); 	

	/** 	
	*Requires: nothing 	
	*Modifies: name, response 
	*Effects: initializes name, and response 	
	*/ 	

	Professor(string n, string t, string r); 

	//destructor 
	~Professor(); 	

	/** 	
	*Requires: nothing 
	*Modifies: name, CP and HP 
	*Effects: get and set values for name, CP and HP 
	*/ 
	string getName() const; 
	string getType() const; 
	string getResponse() const; 
	void setName(string nIn); 
	void setType(string tIn); 
	void setResponse(string rIn); 

	//overloaded operators 
	friend ostream& operator << (ostream& outs, const Professor &p); 	
	/*	friend bool operator < (const Pokemon &lhs, const Pokemon &rhs); //overloading <, and > to compare cp values of pokemon 
	friend bool operator > (const Pokemon &lhs, const Pokemon &rhs);*/ 
	friend bool operator == (const Professor &lhs, const Professor &rhs);

	//overloading == to determine if two professors are the same based off their names 

private: 	
	//fields 	
	string name; //name of professor 	
	string type; //area in which professor specializes in 	
	string response; //professors response to a question 
}; 

class Person { 
public: 
	//default constructor
	/** 
	*Requires: nothing 
	*Modifies: name 	
	*Effects: sets default values for name(" ") 	
	*/ 	
	Person();
	
	/** 
	*Requires: nothing
	*Modifies: name 
	*Effects: initializes name 
	*/ 
	Person(string n); 

	//destructor 
	~Person(); 

	/** 
	*Requires: nothing 
	*Modifies: name 	
	*Effects: get and set values for name 
	*/ 	
	string getName() const; 
	void setName(string tIn);

	//protected: 
	/** 	
	*Requires: nothing 
	*Modifies: nothing
	*Effects: virtual method to return a sentence. 
	*/ 
	virtual string Talk(int index, Student &s) = 0; 

private: 
	//fields 
	string name;//name of person 
}; 

/*Trainer Class***** is a Person ****************************/ 
class Trainer : public Person { 
public: 
	//default constructor 
	/** 
	*Requires: nothing
	*Modifies: vector of professors
	*Effects: sets default values for professor vector to have 1 professor 
	*/
	Trainer();

	//destructor 
	~Trainer();

	/** 
	*Requires: nothing 	
	*Modifies: vector of professor
	*Effects: set values for professor vector 	
	*/ 	
	//void setProfessor(const Professor &pIn);

	/** 	
	*Requires: nothing
	*Modifies: score 
	*Effects: returns score 
	*/ 	
	int getScore(); 	
	
	//overloaded operator prints out what professors are in the vector 
	friend ostream& operator << (ostream& outs, const Trainer & t); 
	
	/** 
	*Requires: nothing 	*Modifies: professors in the vector 	
	*Effects: adds a professor to the vector 
	*/ 
	void addProfessor(Professor p); 
	/** 
	*Requires: nothing 
	*Modifies: professor in the vector 
	*Effects: removes a professor from the vector 
	*/ 	
	void removeProfessor(Professor p); 	
	virtual string Talk(int index, Student &s) override; 

private: 	
	//fields 
	vector<Professor> professorBag; //vector of professor (bag of professors) 
	int score; //score
};

/*Student Class******is a Person****************************************/ 
class Student : public Person { 
public: 
	//default constructor 	
	/** 
	*Requires: nothing 
	*Modifies: question 
	*Effects: sets default value for question("Can you summarize Computer Science in one sentence?") 	
	*/ 
	Student();

	/** 
	*Requires: nothing 
	*Modifies: questionn 
	*Effects: sets value for question 
	*/ 
	Student(string q, string qt); 

	//destructor
	~Student(); 

	/** 
	*Requires: nothing 
	*Modifies: question 
	*Effects: gets/sets value for question
	*/ 
	string getQuestion() const; 
	string getQuestionType() const; 	
	void setQuestion(string qIn); 
	void setQuestionType(string qtIn);
	void setAnswered();
	bool getAnswered();

	//overloaded operator prints out students question 
	friend ostream& operator << (ostream& outs, const Student & s); 

	virtual string Talk(int index, Student &s) override;

private: 
	//fields 	
	string question; //students question 
	string questionType; //type of question 
	bool answered = 0; //sets if question has been answered or not
};


/*Instance Class****** saves and loads instances***********************/

class Instance {
public:
	//default constructor
	/**
	*Requires: nothing
	*Modifies: question
	*Effects: sets default value for question("Can you summarize Computer Science in one sentence?")
	*/
	Instance();

	/**
	*Requires: nothing
	*Modifies: nothing
	*Effects: reads from a file
	*/
	vector<vector<string>> readFile();

	/**
	*Requires: nothing
	*Modifies: nothing
	*Effects:  Prints out a list of highscores
	*/
	void lookUp();

	/**
	*Requires: list of highscores
	*Modifies: nothing
	*Effects: saves to a txt file
	*/
	void write(vector<vector<string>> list);

	/**
	*Requires: playername and score
	*Modifies: nothing
	*Effects: saves to a txt file
	*/
	void Save(int score, string name);
};

class Square {
public: 	
	// initialize variables 
	int xcoord; 
	int ycoord; 

	// Requires: Nothing 
	// Modifies: Nothing 
	// Effects: Nothing 
	// Returns: Nothing 	
	Square(); 	

	// Requires: Two Integers 
	// Modifies: Nothing 
	// Effects: Nothing 
	// Returns: Nothing 
	Square(int x, int y); 	

	// Requires: One Integer 	
	// Modifies: Sets x coordinate on object 
	// Effects: Nothing 	
	// Returns: Nothing 	
	void setXCoord(int x); 	

	// Requires: One Integer 
	// Modifies: Sets y coordinate on object 	
	// Effects: Nothing 
	// Returns: Nothing 	
	void setYCoord(int y); 

	// Requires: Nothing 	
	// Modifies: Nothing 	
	// Effects: Nothing 
	// Returns: One integer 
	int getXCoord(); 

	// Requires: Nothing 
	// Modifies: Nothing 	
	// Effects: Nothing 	
	// Returns: One Integer 
	int getYCoord(); 
};
#endif