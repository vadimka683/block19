#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void show_question(string& question_add) {
	ifstream question;
	question.open(question_add);
	if (!question.is_open()) {
		cout << "Error question file";
		return;
	}
	string str;
	getline(question, str);
	cout << str<<"\n";
}

void check_answer(string& answer_add, int& players_score, int& hall_score) {
	string user_answer;
	cout << "Answer: ";
	cin >> user_answer;

	ifstream answer;
	answer.open(answer_add);
	if (!answer.is_open()) {
		cout << "Error answer file";
		return;
	}
	string correct_answer;
	answer >> correct_answer;
	if (user_answer == correct_answer) {
		cout << "Correct answer\n\n";
		players_score += 1;
		return;
	}
	else {
		cout << "Wrong answer\n\n";
		hall_score += 1;
		return;
	}
}

enum question_or_answer{question = 1,answer = 2};

void choice(string& address, int& number, int& choice_ans_or_quest) {
	if (choice_ans_or_quest & question) {
		ifstream quest;
		quest.open("C:\\Users\\vivas\\Downloads\\Telegram Desktop\\block19\\what where when\\Question.txt");
		if (!quest.is_open()) {
			cout << "Error all question file";
			return;
		}
		int count = 0;
		while (count != number + 1) {
			getline(quest, address);
			count++;
		}
		return;
	}
	else if (choice_ans_or_quest & answer) {
		ifstream quest;
		quest.open("C:\\Users\\vivas\\Downloads\\Telegram Desktop\\block19\\what where when\\Answer.txt");
		if (!quest.is_open()) {
			cout << "Error all answer file";
			return;
		}
		int count = 0;
		while (count != number + 1) {
			getline(quest, address);
			count++;
		}
		return;
	}
}

void paint_world(vector<int>& tab,int& position) {
	cout << "\t\tTABLE" << "\n";
	for (int i = 0; i < 13; i++) {
		if (i == 4 || i == 8) {
			if (i == position) {
				cout << "*\n\t";
			}
			else if (tab[i] != 0) {
				cout << tab[i] << "\n\t";
			}
			else {
				cout << "#\n\t";
			}
		}
		else if (i == 12) {
			if (i == position) {
				cout << "*\n\n";
			}
			else if (tab[i] != 0) {
				cout << tab[i] << "\n\n";
			}
			else {
				cout << "#\n\n";
			}
		}
		else {
			if (i == position) {
				cout << "*\t";
			}
			else if (tab[i] != 0) {
				cout << tab[i] << "\t";
			}
			else {
				cout << "#\t";
			}
		}
	}
}

bool check_win(int& players_score, int& hall_score) {
	if (players_score == 6) {
		cout << "Players winner";
		return false;
	}
	else if (hall_score == 6) {
		cout << "Hall winner";
		return false;
	}
	else {
		cout << "Players have " << players_score << " points\n";
		cout << "Hall has " << hall_score << " points\n\n";
		return true;
	}
}

void play() {
	cout << "\n\tWELCOME TO PLAY\t\n\n";
	vector<int> table;
	int position = 0, players_score = 0, hall_score = 0;
	for (int i = 1; i < 14; i++) {
		table.push_back(i);
	}
	while (check_win(players_score, hall_score)) {
		paint_world(table, position);
		int bias;
		do {
			cout << "Input bias please: ";
			cin >> bias;
			if (bias + position < 0 || bias + position > 12) {
				cout << "Sorry, imposible move, try again\n";
			}
		} while (bias + position < 0 || bias + position > 12);
		position += bias;
		while (table[position] == 0) {
			position = (position + 1) % 13;
		}
		cout << "Playing question number: " << position + 1 << "\n\n";
		string adress;
		int choice_ans_or_quest = question;
		choice(adress, position, choice_ans_or_quest);
		show_question(adress);
		choice_ans_or_quest = ~choice_ans_or_quest;
		choice(adress, position, choice_ans_or_quest);
		check_answer(adress, players_score, hall_score);
		table[position] = 0;
	}
	return;
}

int main() {
	play();
}