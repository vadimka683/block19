#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void check_png(string& add) {
	ifstream user_file;
	user_file.open(add, ios::binary);
	if (!user_file.is_open()) {
		cout << "File error";
		return;
	}
	char check_bits[4];
	user_file.read(check_bits, 4);
	if (check_bits[0] == -119 && check_bits[1] == 'P' && check_bits[2] == 'N' && check_bits[3] == 'G') {
		cout << "The file has the PNG extension.";
	}
	else {
		cout << "The file hasn`t the PNG extension.";
	}
	return;
}

int main() {
	string user_address;
	cout << "Input file address: ";
	getline(cin, user_address);
	check_png(user_address);
}