/*Final Project
Maddie Palmer
James McCracken
Aaron Longchamp
Connor Allan*/

#include "votey.h"
using namespace std;

int main_1() {
	string response;
	cout << "Test the instance class? Y/N ";
	cin >> response;
	if (response == "Y") {
		Instance i;
		cout << "testing the lookUp function" << endl;
		i.lookUp();
		cout << endl << "testing save function" << endl;
		i.Save(321, "Connor");
		i.lookUp();
		cout << endl;
	}
	else
	{

		/*Testing Professor class*************************/
		//testing default constructor with getters
		Professor p;
		cout << "Name from constructor: ";
		cout << p.getName() << endl;
		cout << "Type from constructor: ";
		cout << p.getType() << endl;
		cout << "Response from constructor: ";
		cout << p.getResponse() << endl;

		//testing setters
		cout << "Testing setName, setType and setResponse" << endl;
		p.setName("Bob Erickson"); 	p.setType("Web Design");
		p.setResponse("42");
		cout << "Name after setting a new name: " << p.getName() << endl;
		cout << "Type after setting a new Type: " << p.getType() << endl;
		cout << "Response after setting new response: " << p.getResponse() << endl;

		Professor p2("Jackie Horton", "Java", "Don't use semi-colons!");
		cout << "testing other constructor" << endl;
		cout << p2 << endl << endl;

		Professor p3("Bob Erickson", "Web Design", "42");
		//p should be equal to p3
		//p should NOT be equal to p2
		cout << "Testing overloaded == operator" << endl;
		cout << "Professor p3:" << endl; 	cout << p3 << endl;
		cout << "Is p the same pokemon as p3? " << boolalpha << (p == p3) << endl;
		cout << "Is p the same pokemon as p2 " << boolalpha << (p == p2) << endl << endl;

		cout << "BEGIN TRAINER CLASS TESTING" << endl << endl;

		Trainer trainerA;
		cout << "default professors in bag:" << endl;
		cout << trainerA << endl;

		cout << "Trainer's name from constructor: ";
		cout << trainerA.getName() << endl;
		cout << "Testing setName" << endl;
		trainerA.setName("Maggie");
		cout << "Name after setting a new name: " << trainerA.getName() << endl << endl;

		cout << "testing to remove a professor from bag" << endl;
		cout << "remove professor p" << endl;
		trainerA.removeProfessor(p);
		cout << trainerA << endl << endl;
		cout << "testing adding a professors to bag" << endl;
		cout << "add professor p" << endl;
		trainerA.addProfessor(p);
		cout << trainerA << endl;

		/*Trainer trainerB;
		cout << "testing setProfessor with a new trainer object" << endl;
		trainerB.setProfessor(Professor("Byung Lee", "Algorithms", "Use Dijkstra's Algorithm!"));
		cout << trainerB << endl << endl;*/

		cout << "BEGIN Student CLASS TESTING" << endl << endl;
		Student StudentA;
		cout << StudentA << endl;
		cout << "Student's name from constructor: ";
		cout << StudentA.getName() << endl;

		cout << "Testing setName" << endl;
		StudentA.setName("Maddie");
		cout << "Name after setting a new name: " << StudentA.getName() << endl << endl;

		StudentA.setQuestion("What is the answer to 40 + 2?");
		StudentA.setQuestionType("Web Design");
		cout << "Testing other constructor" << endl;
		Student StudentB("How do you find the shortest path?", "Algorithms");
		cout << StudentB << endl;

		Student StudentC("How do you find the secret key <d,n> in RSA?", "Cryptography");
		Student StudentD("Why does my code have an error?", "Java");
		Student StudentE("What is the concept when a call to a member function causes a different function to be executed depending on the type of object that invokes the function?", "C++");

		cout << "Testing Talk method for Student and Trainer (Student asks a question, Trainer responds)" << endl;
		cout << "Student A's question: " << StudentA.Talk(0, StudentA) << endl;
		cout << "Trainer's response: " << trainerA.Talk(4, StudentA) << endl;
		cout << "Score: " << trainerA.getScore() << endl;
		cout << "Student B's question: " << StudentB.Talk(0, StudentB) << endl;
		cout << "Trainer's response: " << trainerA.Talk(2, StudentB) << endl;
		cout << "Score: " << trainerA.getScore() << endl;
		cout << "Student C's question: " << StudentC.Talk(0, StudentC) << endl;
		cout << "Trainer's response: " << trainerA.Talk(3, StudentC) << endl;
		cout << "Score: " << trainerA.getScore() << endl;
		cout << "Student D's question: " << StudentD.Talk(0, StudentD) << endl;
		cout << "Trainer's response: " << trainerA.Talk(0, StudentD) << endl;//should be wrong answer
		cout << "Score: " << trainerA.getScore() << endl;
		cout << "Student E's question: " << StudentE.Talk(0, StudentE) << endl;
		cout << "Trainer's response: " << trainerA.Talk(0, StudentE) << endl;
		cout << "Score: " << trainerA.getScore() << endl;

		// Testing for Square Class
		Square newSquare = Square::Square(8, 10);
		cout << endl << endl << "New square has been created." << endl;
		int xCoordinate = newSquare.getXCoord();
		cout << "X Coordinate: " << xCoordinate << endl;
		int yCoordinate = newSquare.getYCoord();
		cout << "Y Coordinate: " << yCoordinate << endl;
		newSquare.setXCoord(15);
		newSquare.setYCoord(15);
		xCoordinate = newSquare.getXCoord();
		cout << "New X Coordinate: " << xCoordinate << endl;
		yCoordinate = newSquare.getYCoord();
		cout << "New Y Coordinate: " << yCoordinate << endl;

		return 0;
	}
}
