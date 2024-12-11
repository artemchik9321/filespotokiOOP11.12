// filespotokiOOP11.12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Student
{
	string name;
	string surname;
	int age;
public:
	Student() = default;
	Student(const char* n, const char* sur, int a)
	{
		name = n;
		surname = sur;
		age = a;
	}
	void Print()
	{
		cout << "name " << name << endl << "surname "
			<< surname << endl << "age " << age;
	}
	void SaveFile()
	{
		ofstream write("Student.txt");
		write << "name " << name << endl << "surname "
			<< surname << endl << "age " << age;
	}
	void ReadFile()
	{
		ifstream read("Student.txt");
		if (read) 
		{
			const int size = 200;
			do 
			{
				char buffer[size] = {};
				read.getline(buffer, size);
				cout << buffer << endl;
			} while (read);
			read.close();
		}
		else 
		{
			cout << "erorr " << endl;
		}
	}
};
int main() 
{
	Student Artem("Artem", "SHAMAN", 17);
	Artem.Print();
	Artem.ReadFile();
}