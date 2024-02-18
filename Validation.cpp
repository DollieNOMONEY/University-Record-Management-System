#pragma once
#include <iostream>
#include <string>
//#include "BadInputException.cpp"
using namespace std;

class Validation {
private:
    bool validate_user(string user) {
        if (user.length() < 3) {
            cout << "Username cannot be shorter than 3 characters. Try again.\n";
            return false;
        }
        else if (user.length() > 36) {
            cout << "Username cannot be longer than 36 characters. Try again.\n";
            return false;
        }
        return true;
    }

    bool validate_pass(string pass) {
        if (pass.length() < 8) {
            cout << "Password cannot be shorter than 8 characters. Try again.\n";
            return false;
        }
        else if (pass.length() > 50) {
            cout << "Username cannot be longer than 50 characters. Try again.\n";
            return false;
        }
        return true;
    }
public:

    string input_username() {
        string username;
        while (true) {
            cout << "Enter Username: ";
            cin >> username;
            if (validate_user(username)) { return username; }
        }
    }

    string input_password() {
        string password;
        while (true) {
            cout << "Enter Password: ";
            cin >> password;
            if (validate_pass(password)) { return password; }
        }
    }

    int getChoiceUserInput() {
        int choice;
        bool valid = false;
        do {
            cout << "Enter Option: " << flush; // why << flush?
            cin >> choice;
            if (cin.good()) { // what is good?
                valid = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // learn this
                cout << "Invalid input! Please retry." << endl;
            }
        } while (!valid);
        return choice;
    }

    string input_new_username() {
        string newUsername;
        while (true) {
            cout << "Enter New Username: ";
            cin >> newUsername;
            if (validate_user(newUsername)) { return newUsername; }
        }
    }

    string input_new_password() {
        string newPassword;
        while (true) {
            cout << "Enter New Password: ";
            cin >> newPassword;
            if (validate_user(newPassword)) { return newPassword; }
        }
    }


};