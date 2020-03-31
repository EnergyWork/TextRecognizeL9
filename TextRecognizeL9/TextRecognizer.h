#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <iomanip>
using namespace std;
constexpr auto ART = 0;
constexpr auto LEGAL = 1;
constexpr auto frstSign = 0;
constexpr auto scndSign = 1;
constexpr auto thrdSign = 2;
constexpr auto frthSign = 3;
constexpr auto ffthSign = 4;

/*Либо художественный либо юридический текст*/
class TextRecognizer {
	bool textType;
	string file;
	vector<ifstream> fin;
	void openFile();
	int firstSign();
	bool secondSign();
	bool thridSign();
	bool fourthSign();
	bool fifthSign();
	bool recognize();
public:
	TextRecognizer(string file) {
		this->file = file;
		fin.resize(5);
		openFile();
		textType = ART;
		recognize();
	}
};