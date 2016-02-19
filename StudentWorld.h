#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include <string>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
#include <vector>
#include "Actor.h"
#include "GraphObject.h"


class StudentWorld : public GameWorld {
public:
	StudentWorld(std::string assetDir): GameWorld(assetDir)
    {} // don't touch
    
    ~StudentWorld()
    {}
    
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    
    FrackMan* getFrack() {
        return frackptr;
    }
    
    Dirt* getDirt(int x, int y) {
        return dirtArray[x][y];
    }
    
    void setDirtNull(int x, int y) {
        dirtArray[x][y] = nullptr;
    }
private:
    std::vector<GraphObject*> gameObjects;
    Dirt* dirtArray[64][64];
    FrackMan* frackptr;
};

#endif // STUDENTWORLD_H_
