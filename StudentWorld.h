#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include <string>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
#include <vector>
#include "Actor.h"
#include "GraphObject.h"

// temporary
using namespace std;

class StudentWorld : public GameWorld
{
public:
	StudentWorld(std::string assetDir)
	 : GameWorld(assetDir)
	{}

	virtual int init()
	{
        frackptr = new FrackMan;
        
        for(int i = 0; i < 64; i++)
            for(int j = 0; j < 60; j++) {
                if(i >= 30 && i <= 33)
                    continue;
                dirtArray[i][j] = new Dirt(i, j);
            }
		return GWSTATUS_CONTINUE_GAME;
	}

	virtual int move()
	{
        string gameStatText = "Scr: " + to_string(getScore()) + " Lvl: " + to_string(getLevel()) + " Lives: " + to_string(getLives()) + " Hlth: " + to_string(0) + " Water: " + to_string(0) + " Gld: " + to_string(0) + " Sonar: " + to_string(0) + " Oil left: " + to_string(0);
        // The setGameStatText() method is used to specify what text is displayed at the top of the
        // game screen, e.g.:
        // Scr: 0321000 Lvl: 52 Lives: 3 Hlth: 80% Water: 20 Gld: 3 Sonar: 1 Oil Left: 2
        // You’ll pass in a string to this function that specifies the proper stat values.
        setGameStatText(gameStatText);
        
        frackptr->doSomething();
        
        return GWSTATUS_CONTINUE_GAME;
        
	}

	virtual void cleanUp()
	{
	}
    
    
    

private:
    std::vector<GraphObject*> gameObjects;
    Dirt* dirtArray[64][60];
    FrackMan* frackptr;
    StudentWorld* p_ptr;
};

#endif // STUDENTWORLD_H_
