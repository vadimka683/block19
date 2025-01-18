#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

int main() {
	ifstream user_file;
	user_file.open("C:\\Users\\vivas\\Downloads\\Telegram Desktop\\vocabulary.txt");
	if (!user_file.is_open()) {
		cout << "Error open file";
		return 0;
	}
	string Line, max_line;
	int max_sum = 0, all_sum = 0;
	while (getline(user_file, Line)) {
		stringstream line;
		line << Line;
		cout << Line << "\n";
		string name, sname;
		int pay;
		line >> name >> sname >> pay;
		all_sum += pay;
		if (pay > max_sum) {
			max_sum = pay;
			max_line = Line;
		}
	}
	cout << "Best sum: " << max_line << "\n";
	cout << "All sum: " << all_sum;
}