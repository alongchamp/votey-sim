#include "votey.h"
#include <GL/glut.h>
Instance::Instance()
{
}
/**
*Requires: nothing
*Modifies: nothing
*Effects: Reads from highscores.txt
*/
vector<vector<string>>Instance::readFile() {
	ifstream file("highscores.txt");
	int i = 0;
	string value;
	vector<vector<string>> scoreList;
	vector<string> name;
	vector<string> score;
	while (file.good()) {
		getline(file, value, ';');
		name.push_back(value);
	}
	file.close();
	int vectorSize = name.size();
	for (int i = 0; i < vectorSize; i++) {
		if (i % 2 == 0 && i != 0) {
			scoreList.push_back(score);
			score.clear();
		}
		score.push_back(name[i]);
	}
	return scoreList;
}

/**
*Requires: nothing
*Modifies: nothing
*Effects: Prints out a list of highscores
*/
void Instance::lookUp()
{
	vector<vector<string>> list = readFile();
	for (int j = 0; j < list.size(); j++) {
			for (int i = 0; i < 2; i++) {
				cout << list[j][i] << " ";
			}
		}
	}

/**
*Requires: playername and score
*Modifies: nothing
*Effects: saves to a txt file
*/
void Instance::Save(int score, string name){
	string sScore = to_string(score);
	vector<string> scoreInfo;
	scoreInfo.push_back(sScore);
	scoreInfo.push_back(name);
	vector<vector<string>> list = readFile();
	list.push_back(scoreInfo);
	write(list);
}

/**
*Requires: list
*Modifies: nothing
*Effects: saves to a txt file
*/
void Instance::write(vector<vector<string>> list) {
	ofstream file("highscores.txt");
	if (file) {
		for (int j = 0; j < list.size(); j++) {
			if (j == (list.size()-1)) {
				file << endl;
			}
			for (int i = 0; i < 2; i++) {
				file << list[j][i] + ";";
			}
		}
		file.close();
	}
}