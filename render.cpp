#ifndef RENDER_CPP_CHECK
#define RENDER_CPP_CHECK

#include <iostream>

#ifdef _WIN32
#include <conio.h>
#else
#include <unistd.h>
#endif

#ifdef _WIN32
uint8_t getInput() {
	while (true) {
		uint8_t keyIn = (uint8_t) getch();
		if (keyIn == 3) {exit(0);}
		return keyIn;
	}
}
#else
uint8_t getInput() {
	while (true) {
		system("stty raw");
        uint8_t keyIn = (uint8_t) getchar(); 
        system("stty cooked");
		if (keyIn == 3) {exit(0);}
		return keyIn;
	}
}
#endif

#endif