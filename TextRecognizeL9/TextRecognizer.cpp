#include "TextRecognizer.h"

void TextRecognizer::openFile() {
	for (size_t i = 0; i < fin.size(); i++) {
		fin[i].open(this->file);
	}
}
int TextRecognizer::firstSign() { //словарик
	string s;
	int count = 0, wordsCounter = 0;
	vector<string> words = {
		"тысяч", "рублей", 
		"лиц", "лица",	"лицо",	
		"административного", "административных",
		"статьи", "статья", "статьей", "статьями", "статья",
		"штрафа", "размере", "наложение",		
		"влечет", "российской",	"федерации", "рф",		
		"должностных",	"юридических",	"частью",			
		"нарушение", "кодекса", "кодекс", "настоящего",		
		"правонарушения", "срок", "граждан",	
		"деятельности",	"предусмотренных",	
		"коап",	"власти", "власть", "исполнительной",
		"правонарушении", "законодательством",
		"правонарушениях", "федерального"
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
bool TextRecognizer::secondSign() { //местоимения
	string s;
	int count = 0;
	vector<string> pronouns = { "мы", "я", "вы", "вас", "мой", "твой", "наш", "её" };
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
bool TextRecognizer::thridSign() { //знаки
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
bool TextRecognizer::fourthSign() { // цифры: списки, номера
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
bool TextRecognizer::fifthSign() { //не придумал
	string s;
	while (!fin[ffthSign].eof()) {
		fin[ffthSign] >> s;
	}
	return false;
}
bool TextRecognizer::recognize() {
	cout << "Словарик юр. слов КоАП\'а: " << firstSign() << " слов" << endl;
	cout << "Притяжательные метоимения: " << (secondSign() ? "есть" : "нет") << endl;
	cout << "Знаки воскл., вопроса и многоточия: " << (thridSign() ? "есть" : "нет") << endl;
	cout << "Цифры в чистом виде: " << (fourthSign() ? "есть" : "нет") << endl;
	//fifthSign();
	return false;
}