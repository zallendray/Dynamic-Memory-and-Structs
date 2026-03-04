// Dynamic Memory and Structs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int get_number_of_students(int& num_students, int& num_grades);


int main()
{
	struct student_info
	{
		string name;
		int student_id;
		int* grades = nullptr;
	};
	int num_of_students, num_of_grades;
	cout << get_number_of_students(num_of_students, num_of_grades);
	cout << num_of_students;




}

int get_number_of_students(int& num_students, int& num_grades)
{
	ifstream inputFile;
	inputFile.open("student_data.txt");
	if (inputFile)
	{
		char character;
		string temp;
		int step = 0;

		while (inputFile.get(character)) {
			if (character == ' ' or character == '\n') {
				if (step == 0) {
					int temp_int = stoi(temp);
					num_students = temp_int;
					temp.clear();
					step += 1;
				}
				else {
					int temp_int = stoi(temp);
					num_grades = temp_int;
					return 0;
				}
			}
			else {
				temp += character;
			}
		}
	}
	else
	{
		cout << "ERROR: the specified file does not exist!";
	}

}