#include<iostream>
#include<fstream>
#include<string>
#include<vector>
//C:\Users\vivas\Downloads\Telegram Desktop\vocabulary.txt
using namespace std;

void normal_read(string& add,vector<string>& buf) {
	ifstream user_file;
	user_file.open(add);
	if (!user_file.is_open()) {
		cout << "The file cannot be opened.";
		return;
	}
	string small_buffer;
	while (user_file >> small_buffer) {
		buf.push_back(small_buffer);
	}
}

void binnar_read(string& add, vector<char>& buf) {
	ifstream user_file;
	user_file.open(add, ios::binary);
	if (!user_file.is_open()) {
		cout << "The file cannot be opened.";
		return;
	}
	const size_t small_buff_size = 2;
	char small_buff[small_buff_size];
	while (user_file.read(small_buff, small_buff_size)) {
		buf.insert(buf.end(), small_buff, small_buff + user_file.gcount());
	}
	if (user_file.gcount() > 0) {
		buf.insert(buf.end(), small_buff, small_buff + user_file.gcount());
	}
}

int main() {
	string user_address;
	cout << "Input your file address. Using double slash please: ";
	getline(cin, user_address);
	vector<string> buffer_1;
	vector<char> buffer_2;
	normal_read(user_address, buffer_1);
	binnar_read(user_address, buffer_2);
	for (int i = 0; i < buffer_1.size(); i++) {
		cout << buffer_1[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < buffer_2.size(); i++) {
		cout << buffer_2[i];
	}
}