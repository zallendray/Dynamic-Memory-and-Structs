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
	int average;
	char letter_grade;
	int* grades = nullptr;
};

int get_number_of_students(int& num_students, int& num_grades);

int get_student_data(int num_students, int num_grades, student_info* Student_List);

void calculate_averages(int num_students, int num_grades, student_info* Student_List);

void print_report(int num_students, int num_grades, student_info* Student_List);

int main()
{

	
	student_info* Student_List = nullptr;
	int num_of_students, num_of_grades;
	cout << get_number_of_students(num_of_students, num_of_grades);
	
	Student_List = new student_info[num_of_students];

	get_student_data(num_of_students, num_of_grades, Student_List);
	calculate_averages(num_of_students, num_of_grades, Student_List);
	print_report(num_of_students, num_of_grades, Student_List);
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
				int temp_int = stoi(temp);
				Student_List[student_number].grades[grade_number] = temp_int;
				grade_number += 1;
				temp.clear();

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

void calculate_averages(int num_students, int num_grades, student_info* Student_List)
{
	for (int i = 0; i < num_students; i++) {
		int average = 0;
		for (int in = 0; in < num_grades; in++) {
			average += Student_List[i].grades[in];
		}
		average /= num_grades;
		Student_List[i].average = average;

		if (Student_List[i].average >= 90) {
			Student_List[i].letter_grade = 'A';
		}
		else if (Student_List[i].average >= 80) {
			Student_List[i].letter_grade = 'B';
		}
		else if (Student_List[i].average >= 70) {
			Student_List[i].letter_grade = 'C';
		}
		else if (Student_List[i].average >= 60) {
			Student_List[i].letter_grade = 'D';
		}
		else {
			Student_List[i].letter_grade = 'F';
		}
	}
	
}

void print_report(int num_students, int num_grades, student_info* Student_List)
{
	cout << endl << endl;

	for (int i = 0; i < num_students; i++) {
		cout << "Student Name: " << Student_List[i].name << "     Student ID: " << Student_List[i].id << endl << endl << "Letter Grade: " << Student_List[i].letter_grade << "    Average Grade: " << Student_List[i].average << endl << endl << "Grades:" << endl;
		for (int in = 0; in < num_grades; in++) {
			cout << Student_List[i].grades[in] << endl;
		}
		delete[] Student_List[i].grades;
		cout << endl << endl << endl;
	}
	delete[] Student_List;
}