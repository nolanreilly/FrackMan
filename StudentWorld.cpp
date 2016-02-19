#include "StudentWorld.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp

int StudentWorld::init() {
    frackptr = new FrackMan(this);
    
    for(int i = 0; i < 64; i++) {
        for(int j = 0; j < 64; j++) {
            if((i >= 30 && i <= 33) || (j >= 60 && j <= 63)) {
                dirtArray[i][j] = nullptr;
                continue;
            }
            dirtArray[i][j] = new Dirt(i, j);
        }
    }
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move() {
    setGameStatText("Scr: " + to_string(getScore()) + " Lvl: " + to_string(getLevel()) + " Lives: " + to_string(getLives()) + " Hlth: " + to_string(0) + " Water: " + to_string(0) + " Gld: " + to_string(0) + " Sonar: " + to_string(0) + " Oil left: " + to_string(0));
    
    frackptr->doSomething();
    
    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
    for(int i = 0; i < gameObjects.size(); i++) {
        delete gameObjects[i];
    }
    for(int i = 0; i < 64; i++) {
        for(int j = 0; j < 64; j++) {
            if(dirtArray[i][j] != nullptr)
                delete dirtArray[i][j];
        }
    }
}