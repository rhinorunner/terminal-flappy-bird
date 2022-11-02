#include <iostream>
#include <vector>
#include "render.h"

typedef struct s_Game {
	// BIRD
	short height;
	short x; //keep this constant?
	//{{forHowManyFrames,moveThisHeight}...}
	//take index 0
	std::vector<std::pair<uint8_t,uint8_t>> gravity {};

	// PIPES
	//{{{wallOpening0,wallOpening1},xLocationOnScreen}...}
	//print all of em
	std::vector<std::pair<std::pair<uint8_t,uint8_t>,uint8_t>> pipes {};

	// SCORE
	int 	highScore;
	uint8_t pipeGap = 5;
	//std::vector<int> scores;

	// BLITS
	char birdBlit = '@', 
		 backBlit = ' ',
		 pipeBlit = '=';
} Game;

class GameRender {
private:
	//40x15 is a good size
	std::pair<short,short> screenSize;
	Game thisGame;
public:
	GameRender(const std::pair<short,short>& screensize, Game& thisgame) : screenSize(screensize),thisGame(thisgame) {}
	void printScreen() {
		for (short y = 0; y < screenSize.second; ++y) {
			for (short x = 0; x < screenSize.first; ++x) {
				std::cout << thisGame.backBlit;
			}
		std::cout << "\n";
		}
	}
	void createPipe() {
		short pipeOutTop = random() % screenSize.first;
		if (pipeOutTop >= screenSize.first - thisGame.pipeGap) {
			short pipeOutBottom = pipeOutTop - thisGame.pipeGap;
		}
	}
};

int main() {
	Game f_game;
	GameRender f_render{{40,15},f_game};
	f_render.printScreen();
	return 0;
}