#pragma once
#include <iostream>
#include <thread>
#include "Validation.cpp"
#include "RecordManagement.cpp"
#include "Account.cpp"
#include "ApplicationFunctions.cpp"
using namespace std;


enum {
	QUIT = 0,
	ADD = 1,
	UPDATE,
	DELETE,
	SORT,
	SEARCH,
	VIEW,
	CONFIRM,
	CHANGE_NAME,
	CHANGE_PASS,
	DELETE_ACC,
	LOGOUT_ACC,
	SAVEALL,
	SAVE_ONE,
	LOAD
};





class Application {
private:
	Validation validate;
	RecordManagement rm;
	AdminAccount log;
	ApplicationFunctions func;

	void displayManagementMenu() {
		cout << "University Record Management System\t\t\t\t" << "User: " << log.getUsername() << "\n\n";
		cout << "Manage Undergraduated Students: " << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "\t1. Add Undergraduate" << endl;
		cout << "\t2. Update Information of Undergraduate (NOT COMPLETED)" << endl;
		cout << "\t3. Delete Undergraduate" << endl;
		cout << "\t4. Sort Undergraduate (NOT COMPLETED)" << endl;
		cout << "\t5. Search for an Undergraduate" << endl;
		cout << "\t6. View all Undergraduates" << endl;
		cout << "\t7. Confirm Undergraduate (NOT COMPLETED)" << endl;
		cout << endl;
		cout << "Account Settings:" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "\t8. Change username" << endl;
		cout << "\t9. Change password" << endl;
		cout << "\t10. Delete account" << endl;
		cout << "\t11. Logout account" << endl;
		cout << endl;
		cout << "Program Settings:" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "\t0. Exit Program\n\n" << endl;
		cout << "\Auto saved is disabled. Any data added will be lost.\n\n" << endl;
	}

	void displayAuthenticationMenu() {
		cout << "University Record Management System" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "Press 1 to Login" << endl;
		cout << "Press 2 to Register" << endl;
		cout << "Press 3 to Exit" << endl;
	}

	void displayExitMenu() {
		cout << "University Record Management System" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "Thank you for using our service." << endl;
	}
public:
	Application() {};

	void manageUniversity() {
		bool loggedOut = false;
		int choice;
		do {

			displayManagementMenu();
			choice = validate.getChoiceUserInput();

			switch (choice) {
			case ADD: {
				rm.add();
				break;
			}
			case DELETE: {
				rm.del();
				break;
			}
			case SEARCH: {
				rm.search();
				break;
			}
			case VIEW: {
				rm.view();
				break;
			}
			case CHANGE_NAME: {
				func.clearScreen();
				string newUsername = validate.input_new_username();
				log.changeName(newUsername);
				func.clearScreen();
				cout << "Updating your username..." << endl;
				func.wait(2);
				func.clearScreen();
				func.loadingScreen();
				func.clearScreen();
				cout << "Updating username successful." << endl;
				func.wait(2);
				func.clearScreen();
				break;
			}
			case CHANGE_PASS: {
				func.clearScreen();
				string newPassword = validate.input_new_password();
				log.changePass(newPassword);
				func.clearScreen();
				cout << "Updating your password..." << endl;
				func.wait(2);
				func.clearScreen();
				func.loadingScreen();
				func.clearScreen();
				cout << "Updating password successful." << endl;
				func.wait(2);
				break;
			}
			case DELETE_ACC: {
				bool del = log.deleteAccount();
				func.clearScreen();
				cout << "Deleting account..." << endl;
				func.wait(2);
				func.clearScreen();
				func.loadingScreen();
				func.clearScreen();
				cout << "You have been logged out." << endl;
				func.wait(2);
				if (del == true) {
					loggedOut = true;
				}
				break;
			}
			case LOGOUT_ACC: {
				func.loadingScreen();
				func.clearScreen();
				cout << "You have been logged out." << endl;
				func.wait(2);
				loggedOut = true;
				break;
			}
			case QUIT: {
				func.loadingScreen();
				func.clearScreen();
				displayExitMenu();
				func.wait(2);
				exit(1);
			}
			}

		} while (loggedOut == false);

	}

	void run() {
		int userChoice = 0;

		do {
			func.clearScreen();
			displayAuthenticationMenu();
			userChoice = validate.getChoiceUserInput();

			switch (userChoice) {
			case 1:
				func.clearScreen();
				if (log.userLogin() == true) {
					func.wait(2);
					func.loadingScreen();
					func.clearScreen();
					manageUniversity();
				}
				else {
					func.wait(2);
				}
				break;
			case 2:
				func.clearScreen();
				log.userRegister();
				func.wait(2);
				break;
			case 3:
				func.loadingScreen();
				func.clearScreen();
				displayExitMenu();
				func.wait(2);
				exit(1);
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
			}
		} while (userChoice != 0);
		
	}
};



