#include "Loading.h"

#include <iostream>
#include <string>
#include <Windows.h>

void loading(int rep = 5) {
	std::string loadingPoints = ". . .";
	for (int i = 0; i < rep; i++) {
		system("cls");
		std::cout << "Loading ";
		for (char c : loadingPoints) {
			std::cout << c;
			Sleep(350);
		}
		std::cout << std::endl;
	}
	system("cls");
}
