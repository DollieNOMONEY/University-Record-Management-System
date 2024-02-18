#pragma once
#include <iostream>
#include <thread>
using namespace std;


class ApplicationFunctions {
public:
	void clearScreen() {
		system("cls");
	}

	void loadingScreen() {
		for (int i = 0; i <= 3000; i++) {
			cout << "LOADING..." << endl;
		}
	}

	void addLines() {
		cout << "\n\n\n";
	}

	void wait(int num) {
		this_thread::sleep_for(chrono::seconds(num));
	}
};