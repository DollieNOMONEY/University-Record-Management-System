#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "Validation.cpp"
using namespace std;

class Account {
protected:
    string username;
    string password;

public:
    virtual bool userLogin() = 0;
    virtual bool userRegister() = 0;
};


class AdminAccount : public Account {
private:
    Validation validate;
public:
    string getUsername() const {
        return username;
    }
    string getPassword() const {
        return password;
    }

    bool userLogin() override {
        bool userFound = false;
        string fileUsername, filePassword;

        username = validate.input_username();
        password = validate.input_password();

        ifstream fin("users.dat", ios::in);
        if (!fin.is_open()) {
            cerr << "Cannot open file" << endl;
            return false;
        }
        while (fin >> fileUsername >> filePassword) {
            if (fileUsername == username && filePassword == password) {
                userFound = true;
                break;
            }
        }
        fin.close();
        if (!userFound) {
            cout << "Username or Password is incorrect!" << endl;
        }
        else {
            cout << "\n\nLogin successful! Now redirecting you to the Home Page." << endl;
        }

        return userFound;
    }
    bool userRegister() override {
    tryagain:
        username = validate.input_username();

        //Check if username already exists
        std::ifstream userFiles("users.dat"); 
        if (!userFiles.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            return false;
        }

        string line, username2, password;
        while (getline(userFiles, line)) {
            istringstream iss(line);
            iss >> username2 >> password;  // Read into separate variables

            if (username == username2) {
                cout << "Username already exists. Try again.\n";
                goto tryagain;
            }
        }
        userFiles.close();


        password = validate.input_password();

        ofstream fout("users.dat", ios::out | ios::app);
        if (!fout.is_open()) {
            cerr << "Cannot open file" << endl;
            return false;
        }
        fout << username << " " << password << endl;
        fout.close();

        cout << "\n\nUser created!";
    }

    bool changeName(string newUsername) {
        const char* filename = "users.dat";
        string line;
        ofstream outputFile("temp.dat");

        vector<string> lines;
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return false;
        }

        while (getline(inputFile, line)) {
            lines.push_back(line);
        }
        inputFile.close();

        if (!outputFile.is_open()) {
            cerr << "Error opening temporary file: temp.dat" << endl;
            return false;
        }
        
        for (const auto& line : lines) {
            if (line.find(this->username) == string::npos) { // Username not found in line
                outputFile << line << endl;
            }
            else {
                string lineN = newUsername + " " + password; // Replace entire username section
                outputFile << lineN << endl;
            }
        }
        outputFile.close();

        remove(filename);
        if (rename("temp.dat", filename) != 0) {  // Use filename directly, as it's already a const char *
            cerr << "Error renaming temporary file: temp.dat to " << filename << endl;
            return false;
        }
        this->username = newUsername;

        return true;
    }
    bool changePass(string newPassword) {
        const char* filename = "users.dat";
        string line;
        ofstream outputFile("temp.dat"); 

        vector<string> lines;
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return false;
        }

        while (getline(inputFile, line)) {
            lines.push_back(line);
        }
        inputFile.close();

        if (!outputFile.is_open()) {
            cerr << "Error opening temporary file: temp.dat" << endl;
            return false;
        }

        for (const auto& line : lines) {
            if (line.find(this->username) == string::npos) {
                outputFile << line << endl;
            }
            else {
                string lineN = username + " " + newPassword;
                outputFile << lineN << endl;
            }
        }

        outputFile.close();
        remove(filename);
        if (rename("temp.dat", filename) != 0) {  // Use filename directly, as it's already a const char *
            cerr << "Error renaming temporary file: temp.dat to " << filename << endl;
            return false;
        }
        this->password = newPassword;

        return true;
    }

    bool deleteAccount() {
        const char* filename = "users.dat";
        string line;
        ofstream outputFile("temp.dat");

        vector<string> lines;
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return false;
        }
       
        while (getline(inputFile, line)) {
            lines.push_back(line);
        }
        inputFile.close();
 
        if (!outputFile.is_open()) {
            cerr << "Error opening temporary file: temp.dat" << endl;
            return false;
        }
        
        for (const auto& line : lines) {
            if (line.find(this->username) == string::npos) { // Username not found in line
                outputFile << line << endl;
            }
        }
        outputFile.close();

        remove(filename);
        if (rename("temp.dat", filename) != 0) {  // Use filename directly, as it's already a const char *
            cerr << "Error renaming temporary file: temp.dat to " << filename << endl;
            return false;
        }

        return true;
    }
};