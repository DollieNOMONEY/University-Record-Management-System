#pragma once
#include <iostream>
using namespace std;

class BadInputException : public exception {
public:
    explicit BadInputException(const string& message) : message_(message) {}

    const char* what() const throw() override {
        return message_.c_str();
    }

private:
    string message_;
};