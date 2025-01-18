#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	ifstream vac;
	vac.open("C:\\Users\\vivas\\OneDrive\\Рабочий стол\\Skillbox\\блок19\\vocabulary.txt");
	string search_word;
	cout << "Input search word: ";
	cin >> search_word;
	int count = 0;
	while (!vac.eof()) {
		string word;
		vac >> word;
		if (word == search_word) {
			count++;
		}
	}
	cout<<"The searched word occurred: "<< count<<" times";
}