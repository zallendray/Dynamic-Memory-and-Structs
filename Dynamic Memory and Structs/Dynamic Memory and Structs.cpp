// Dynamic Memory and Structs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct student_info
{
	string name;
	int id;
	int* grades = nullptr;
};

int get_number_of_students(int& num_students, int& num_grades);

int get_student_data(int num_students, int num_grades, student_info* Student_List);

int main()
{

	
	student_info* Student_List = nullptr;
	int num_of_students, num_of_grades;
	cout << get_number_of_students(num_of_students, num_of_grades);
	
	Student_List = new student_info[num_of_students];

	get_student_data(num_of_students, num_of_grades, Student_List);

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

int get_student_data(int num_students, int num_grades, student_info* Student_List)
{
	ifstream inputFile;
	inputFile.open("student_data.txt");
	if (inputFile)
	{
		char character;
		string temp;
		int step = 0, student_number = 0,grade_number = 0;
		bool get_data = false;

		while (inputFile.get(character)) 
		{
			if (get_data == false) 
			{
				if (character == '\n') 
				{
					get_data = true;
				}
			}
			else if (character == ' ') 
			{
				if (step == 0) 
				{
					Student_List[student_number].name = temp;
					temp.clear();
					step += 1;
				}
				else if (step == 1) 
				{
					int temp_int = stoi(temp);
					Student_List[student_number].id = temp_int;
					temp.clear();
					step += 1;
					Student_List[student_number].grades = new int[num_grades];
				}
				else 
				{
					int temp_int = stoi(temp);
					Student_List[student_number].grades[grade_number] = temp_int;
					grade_number += 1;
					temp.clear();
				}
			}
			else if (character == '\n') 
			{
				if (student_number == num_students - 1) {
					int temp_int = stoi(temp);
					Student_List[student_number].grades[grade_number] = temp_int;
					grade_number += 1;
					temp.clear();
				}
				student_number += 1;
				grade_number = 0;
				step = 0;
			}
			else {
				temp += character;
			}
		}
	}
	else
	{
		cout << "ERROR: the specified file does not exist!";
		return 0;
	}

}