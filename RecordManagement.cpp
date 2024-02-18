#pragma once
#include <iostream>
#include <string> 
#include <cstdlib>
#include <sstream>
#include "ApplicationFunctions.cpp"
#include "Undergraduate.cpp"
#include "BadInputException.cpp"
using namespace std;

class RecordManagement {
private:
	ApplicationFunctions func;
	int value;
	Undergraduate undergraduate;
	vector<Undergraduate> undergraduateList;

public:
	RecordManagement() : value(0) {}

	void add() {
		string undergraduateName;
		char undergraduateGender;
		string undergraduateDateOfBirth;
		string undergraduateAddress;
		string undergraduateGuardian1Name;
		string undergraduateGuardian2Name;

		int undergraduateSATScores;
		float undergraduateGPA;
		string undergraduateMajor;
		string undergraduateMinor;

		func.clearScreen();

		// undergraduateName
		while (true) {
			try {
				string createdName;
				cout << "What's the Undergraduate's name?: ";
				getline(cin, createdName);

				if (createdName.empty()) {
					throw BadInputException("Error: Name cannot be empty.");
				}
				else {
					undergraduateName = createdName;
					break;
				}
			}
			catch (const BadInputException& e) {
				cout << e.what() << endl;
				
			}
		}

		// undergraduateGender
		while (true) {
			try {
				char createdGender;
				cout << "What's the Undergraduate's gender?: ";
				cin >> createdGender;

				if (createdGender != 'M' && createdGender != 'F') {
					throw BadInputException("Error: Invalid gender format (M/F required).");
				}
				else {
					undergraduateGender = createdGender;
					break;
				}
			}
			catch (const BadInputException& e) {
				cout << e.what() << endl;

			}
		}

		cout << "What's the Undergraduate's date of birth? (d/m/y): ";
		cin >> undergraduateDateOfBirth;
		cin.get();

		cout << "What's the Undergraduate's address?: ";
		getline(cin, undergraduateAddress);

		cout << "What's the Undergraduate's first guardian?: ";
		getline(cin, undergraduateGuardian1Name);

		cout << "What's the Undergraduate's second guardian?: ";
		getline(cin, undergraduateGuardian2Name);

		bool flag = false;
		do {
			cout << "What's the Undergraduate's SAT Scores?: ";
			string input;
			std::getline(cin, input);

			istringstream ss(input);
			int score;
			if (ss >> score) {
				if (score >= 400 && score <= 1600) {
					undergraduateSATScores = score;
					flag = true;
				}
				else {
					std::cout << "Invalid score. Please enter a number between 400 and 1600." << std::endl;
				}
			}
			else {
				std::cout << "Invalid input. Please enter a number." << std::endl;
			}
		} while (!flag);

		
		bool flag2 = false;
		do {
			cout << "What's the Undergraduate's GPA?: ";
			string input;
			std::getline(cin, input);

			istringstream ss(input);
			int score;
			if (ss >> score) {
				if (score >= 0.0 && score <= 4.0) {
					undergraduateGPA = score;
					flag2 = true;
				}
				else {
					std::cout << "Invalid score. Please enter a number between 0.0 and 4.0." << std::endl;
				}
			}
			else {
				std::cout << "Invalid input. Please enter a number." << std::endl;
			}
		} while (!flag2);

		cout << "What's the Undergraduate's major?: ";
		cin >> undergraduateMajor;
		cout << "What's the Undergraduate's minor?: ";
		cin >> undergraduateMinor;


		func.loadingScreen();
		system("cls");
		Undergraduate newUndergraduate(undergraduateName, undergraduateGender, undergraduateDateOfBirth, undergraduateAddress,
			undergraduateGuardian1Name, undergraduateGuardian2Name, undergraduateSATScores, undergraduateGPA, undergraduateMajor, 
			undergraduateMinor);


		undergraduateList.push_back(newUndergraduate);


		cout << "Undergraduate information added!";
		func.wait(3);
		system("cls");	
	}

	void search() {
		func.clearScreen();
		string nameInput;
		cout << "Type name of undergraduate to search: ";
		cin >> nameInput;
		func.loadingScreen();
		system("cls");
		try {
			auto foundUndergraduate = std::find_if(undergraduateList.begin(), undergraduateList.end(),
				[&nameInput](const Undergraduate& undergraduate) {
					return undergraduate.getName() == nameInput;
				});

			if (foundUndergraduate != undergraduateList.end()) {
				foundUndergraduate->printInfo();
				cout << endl << "Found!" << endl;
			}
			else {
				throw std::runtime_error("Undergraduate not found");
			}

		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		func.wait(3);
		system("cls");
	}

	void del() {
		func.clearScreen();
		string nameInput;
		cout << "Enter name of undergraduate to delete: ";
		cin >> nameInput;
		func.loadingScreen();
		system("cls");
		try {
			auto foundUndergraduate = std::find_if(undergraduateList.begin(), undergraduateList.end(),
				[&nameInput](const Undergraduate& undergraduate) {
					return undergraduate.getName() == nameInput;
				});

			if (foundUndergraduate != undergraduateList.end()) {
				undergraduateList.erase(foundUndergraduate);
				std::cout << "Undergraduate deleted successfully." << std::endl;
			}
			else {
				throw std::runtime_error("Undergraduate not found");
			}

		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		func.wait(3);
		system("cls");

	}

	void view() {
		system("cls");
		cout << "List of all undergraduates:" << endl;
		
		for (const Undergraduate& undergraduate : undergraduateList) {
			undergraduate.printInfo();
		}

		func.wait(3);
		system("cls");
	}
};