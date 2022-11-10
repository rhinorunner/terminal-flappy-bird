#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "render.h"

typedef struct s_Game {
	// BIRD
	uint16_t height;
	uint16_t x; //keep this constant?
	//{{forHowManyFrames,moveThisHeight}...}
	//take index 0
	std::vector<std::pair<uint8_t,uint8_t>> gravity {};

	// PIPES
	//{{{wallOpeningTop,wallOpeningBottom},xLocationOnScreen}...}
	//print all of em
	std::vector<std::pair<std::pair<uint16_t,uint16_t>,uint8_t>> pipes {};

	// SCORE
	uint32_t highScore;
	uint8_t  pipeGap = 5;
	//std::vector<int> scores;

	// BLITS
	char birdBlit = '@', 
		 backBlit = ' ',
		 pipeBlit = '=';
} Game;

class GameRender {
private:
	//40x15 is a good size
	std::pair<uint16_t,uint16_t> screenSize;
	Game thisGame;

public:
	GameRender(const std::pair<uint16_t,uint16_t>& screensize, Game& thisgame) : screenSize(screensize),thisGame(thisgame) {}

	void printScreen() {
		for (uint16_t y = 0; y < screenSize.second; ++y) {
			for (uint16_t x = 0; x < screenSize.first; ++x) {
				std::cout << thisGame.backBlit;
			}
		std::cout << "\n";
		}
	}

	void createPipe() {
		// create top point for pipe
		uint16_t pipeOutTop = random() % screenSize.first + thisGame.pipeGap;
		// create bottom point
		if (pipeOutTop >= screenSize.first - thisGame.pipeGap) {
			uint16_t pipeOutBottom = pipeOutTop - thisGame.pipeGap;
		}
		else {
			uint16_t pipeOutBottom = pipeOutTop + thisGame.pipeGap;
		}
		thisGame.pipes.push_back({pipeOutTop,pipeOutBottom},screenSize);
	}

	void printDebugInfo() {
		// print pipe info
		for (std::pair<std::pair<uint16_t,uint16_t>,uint8_t> x : thisGame.pipes) {
			std::cout << "{" << x.first.first << ", " << x.first.second << "}, " << x.second << "\n";
		}
		}
	}
};

int main() {
	Game f_game;
	GameRender f_render{{40,15},f_game};
	f_render.printScreen();
	f_render.createPipe();
	f_render.printDebugInfo();
	return 0;
}