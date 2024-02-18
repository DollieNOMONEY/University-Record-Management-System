#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Undergraduate {
private:
    int value;

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
public:
    Undergraduate() : value(0) {}

    Undergraduate(string name, char gender, string dOFb, string address, string guardian1, string guardian2,
        int satscores, int gpa, string major, string minor ) {
        undergraduateName = name;
        undergraduateGender = gender;
        undergraduateDateOfBirth = dOFb;
        undergraduateAddress = address;
        undergraduateGuardian1Name = guardian1;
        undergraduateGuardian2Name = guardian2;
        undergraduateSATScores = satscores;
        undergraduateGPA = gpa;
        undergraduateMajor = major;
        undergraduateMinor = minor;
    }

    string getName() const {
        return undergraduateName;
    }

    void printInfo() const {
        cout << undergraduateName << " " << undergraduateGender << " " << undergraduateDateOfBirth << " " << undergraduateAddress
            << " " << undergraduateGuardian1Name << " " << undergraduateGuardian2Name << " " << undergraduateSATScores
            << " " << undergraduateGPA << " " << undergraduateMajor << " " << undergraduateMinor
            << " ";
    }

};