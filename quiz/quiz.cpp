#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
using namespace std;
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
vector<int> check_repeat(30, 0);
string question;
string answer;
char user_asnwer;
int counter = 0;
int score = 0;
char hold;
int leaderboard_score()
{
	int score;
	string name;
	ifstream file("highest_c++_score.txt");
	file >> name >> score;
	return score;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void update_score(string name, int score)
{
	ofstream file("highest_c++_score.txt");
	file << name << " " << score;

}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void display_score()

{
	ifstream file("highest_c++_score.txt");
	string name;
	string ch;
	int score;

	file >> name >> score;
	cout << name << " has the heighest Score of " << score << endl;



	cout << "Enter any key and hit Enter !!\n";
	cin >> ch;

}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void startquizeasy() {
	while (counter < 10) {
		int line_counter = 0;
		int rand_line = rand() % 10;
		if (check_repeat[rand_line] == 0) {
			check_repeat[rand_line] = 1;
			ifstream file("quiz_easy.txt", ios::in);
			if (file.is_open()) {
				while (rand_line != line_counter) {
					getline(file, question);
					getline(file, answer);
					line_counter++;
				}
				getline(file, question);
				getline(file, answer);
			}
			cout << "Question Number: " << counter + 1 << endl;
			cout << question << endl;
			cin >> user_asnwer;
			user_asnwer = toupper(user_asnwer);
			if (answer[0] == user_asnwer) {
				cout << "\t\t\t  Congratulation !!!" << endl;
				cout << "\t\t\t  Press  S save  or Press any Key and Enter to continue !!!" << endl;
				score += 20;
				cin >> (hold);
			}
			else {
				cout << "Question Number: " << counter + 1 << endl;
				cout << question << endl;
				cout << "Correct Answer : " << answer << endl;
				cout << "You choose the incorrect answer Please press any key to continue" <<endl;
				cin >> (hold);
			}
			counter++;
		}

	}
	string name;
	cout << "Can you enter your name again I forgot your name" << endl;
	cin >> name;
	cout << "\t\t" << name << " You have completed the quiz!!\n\n";
	if (score >= leaderboard_score()) {
		cout << "\t\tYou are the at theleaderboard with the highest Score!!\n" << endl;
		update_score(name, score);
	}
	cout << "Your Score is: " << score << endl;
	cout << "\n\n";
	char option;
	cout << "To Quit press X " << endl;
	cin >> option;
	option = toupper(option);
	if (option == 'X') {
		exit(1);
	}
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void startgame() {

	cout << "\n> Rules:-\n";
	cout << "There is total of 10 questions. Every true answer will add +20points to your score\n";
	cout << "There will be 4 answers  A====B====C====D\n\n";

	cout << "\n\t\t > Press S to start the default quiz";
	cout << "\n\t\t > Press L to view the Leaderboard";
	cout << "\n\t\t > Press Q to view the other quizs ";
	cout << "\n\t\t > press X to quit\n ";

}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void Quiz() {
	//ofstream file("questions.txt");
	string name;
	cout << "@@@@@@@@@@@@@@@@@@@@@Enter your name@@@@@@@@@@@@@@@@@@@@@" << endl;
	cin >> name;
	cout << "Welcome " << name << " to Quiz\n" << endl;

	startgame();


	char option;
	cin >> option;
	option = toupper(option);
	if (option == 'L') {
		display_score();
	}
	else if (option == 'Q') {
		int quiz_option;
		cout << "\n\t\t > Quiz easy";
		cout << "\n\t\t > Press 1 to start the Easy Quiz\n\n";
		cin >> quiz_option;
		if (quiz_option == 1) {
			startquizeasy();
		}
	}
	else if (option == 'S') {
		while (counter < 10) {

			int line_counter = 0;
			int rand_line = rand() % 24;
			if (check_repeat[rand_line] == 0) {

				check_repeat[rand_line] = 1;


				ifstream file("questions.txt", ios::in);
				if (file.is_open()) {
					while (rand_line != line_counter) {
						getline(file, question);
						getline(file, answer);
						line_counter++;
					}
					getline(file, question);
					getline(file, answer);
				}
				cout << "Question Number: " << counter + 1 << endl;
				cout << question << endl;
				cin >> user_asnwer;
				user_asnwer = toupper(user_asnwer);
				if (answer[0] == user_asnwer) {
					cout << "\t\t\t  Congratulation !!!" << endl;
					score += 20;
					cin >> (hold);
				}
				else {
					cout << "Question Number: " << counter + 1 << endl;
					cout << question << endl;
					cout << "Correct Answer : " << answer << endl;
					cin >> (hold);
				}
				counter++;
			}

		}
		cout << "\t\tYou have completed the quiz!!\n\n";
		if (score >= leaderboard_score()) {
			cout << "\t\tYou are the at theleaderboard with the highest Score!!\n" << endl;
			update_score(name, score);
		}
		cout << "Your Score is: " << score << endl;
		cout << "\n\n";
		cout << "To Quit press X " << endl;
		cin >> option;
		option = toupper(option);
		if (option == 'X') {
			exit(1);
		}
		


	}
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main() {
	
	Quiz();

}