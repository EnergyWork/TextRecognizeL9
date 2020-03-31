#include "TextRecognizer.h"

void TextRecognizer::openFile() {
	for (size_t i = 0; i < fin.size(); i++) {
		fin[i].open(this->file);
	}
}
int TextRecognizer::firstSign() { //��������
	string s;
	int count = 0, wordsCounter = 0;
	vector<string> words = {
		"�����", "������", 
		"���", "����",	"����",	
		"�����������������", "����������������",
		"������", "������", "�������", "��������", "������",
		"������", "�������", "���������",		
		"������", "����������",	"���������", "��",		
		"�����������",	"�����������",	"������",			
		"���������", "�������", "������", "����������",		
		"��������������", "����", "�������",	
		"������������",	"���������������",	
		"����",	"������", "������", "��������������",
		"��������������", "�����������������",
		"���������������", "������������"
	};
	while (!fin[frstSign].eof()) {
		fin[frstSign] >> s;
		transform(s.begin(), s.end(), s.begin(), tolower);
		wordsCounter++;
		for (auto el : words) {
			size_t f = s.find(el);
			if (f != string::npos)
				count++;
		}
	}
	int hz = count;
	return hz;
}
bool TextRecognizer::secondSign() { //�����������
	string s;
	int count = 0;
	vector<string> pronouns = { "��", "�", "��", "���", "���", "����", "���", "�" };
	while (!fin[scndSign].eof()) {
		fin[scndSign] >> s;
		transform(s.begin(), s.end(), s.begin(), tolower);
		for (auto el : pronouns) {
			size_t f = s.find(el);
			if (f != string::npos && s.size() == el.size())
				count++;
		}
	}
	return (count ? 1 : 0);
}
bool TextRecognizer::thridSign() { //�����
	string s;
	int count = 0;
	vector<string> signs = { "!", "?", "..." };
	while (!fin[thrdSign].eof()) {
		fin[thrdSign] >> s;
		for (auto el : signs) {
			size_t f = s.find(el);
			if (f != string::npos)
				count++;
		}
	}
	return (count ? 1 : 0);
}
bool TextRecognizer::fourthSign() { // �����: ������, ������
	string s;
	vector<string> ex = { ".", ",", ";", "(", ")", "!", "?", "..." };
	vector<string> dig = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	int count = 0;
	while (!fin[frthSign].eof()) {
		fin[frthSign] >> s;
		for (size_t i = 0; i < ex.size(); i++) {
			size_t found = s.find(ex[i]);
			if (found != string::npos) {
				s.erase(found, 1);
				i--;
			}
		}
		for (auto el : dig) {
			size_t f = s.find(el);
			if (f != string::npos)
				count++;
		}
	}
	return (count ? 1 : 0);
}
bool TextRecognizer::fifthSign() { //�� ��������
	string s;
	while (!fin[ffthSign].eof()) {
		fin[ffthSign] >> s;
	}
	return false;
}
bool TextRecognizer::recognize() {
	cout << "�������� ��. ���� ����\'�: " << firstSign() << " ����" << endl;
	cout << "�������������� ����������: " << (secondSign() ? "����" : "���") << endl;
	cout << "����� �����., ������� � ����������: " << (thridSign() ? "����" : "���") << endl;
	cout << "����� � ������ ����: " << (fourthSign() ? "����" : "���") << endl;
	//fifthSign();
	return false;
}