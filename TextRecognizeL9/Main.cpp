#include "TextRecognizer.h"

bool pred(const pair<string, uint32_t> &a, const pair<string, uint32_t> &b) {
	return a.second > b.second;
}

void func() {
	ifstream fin("koap1.txt");
	ofstream fout("hz.txt");
	string word;
	bool fl;
	vector<string> exceptions = {
		"в", "и", "или", "-", "за", "до", "либо", "о", "по", "не", "с", "об", "к", "а", "без",
		"из", "со", "(или)", "на", "от", "для", "(в", "(за"
	};
	vector<string> ex = { ".", ",", ";", "(", ")" };
	map<string, uint32_t> slovaric; 
	cout << word.max_size() << endl;
	while (!fin.eof()) {
		fl = false;
		fin >> word;
		transform(word.begin(), word.end(), word.begin(), tolower);
		for (auto el : exceptions) {
			if (word == el)
				fl = true;
		}
		if (fl) continue;
		for (size_t i = 0; i < ex.size(); i++) {
			size_t found = word.find(ex[i]);
			if (found != string::npos) {
				word.erase(found, 1);
				i--;
			}
		}
		if (slovaric.find(word) != slovaric.end()) {
			slovaric[word]++;
		} else {
			slovaric[word] = 1;
		}
	}
	
	vector<pair<string, uint32_t>> vec(slovaric.begin(), slovaric.end());
	sort(vec.begin(), vec.end(), pred);

	for (auto el : vec) {
		fout << el.first << setw(5) << el.second << endl;
	}
	fout.close();
	fin.close();
	return;
}

int main() {
	setlocale(0, "rus");
	//func();
	TextRecognizer *trecx = new TextRecognizer("Text1.txt");

	return 0;
}