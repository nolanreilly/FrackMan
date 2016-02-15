#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameConstants.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

//#include "GameWorld.h"

class Dirt: public GraphObject {
public:
    Dirt(int x, int y): GraphObject(IID_DIRT, x, y, right, 0.25) {
        setVisible(true);
    }
private:
};

class Actor: public GraphObject {
public:
    Actor(int IID, int x, int y): GraphObject(IID, x, y) {
        m_health = 100;
    }
    int getHealth() {
        return m_health;
    }

    virtual void doSomething() = 0;
private:
    int m_health;
};

class FrackMan: public Actor {
public:
    FrackMan(): Actor(IID_PLAYER, 30, 60) {
        setVisible(true);
    }
    ~FrackMan() {
        setVisible(false);
    }
    virtual void doSomething();
    
    // getKey() can be used to determine if the user has hit a key on the keyboard to move the
    // player or to fire. This method returns true if the user hit a key during the current tick, and
    // false otherwise (if the user did not hit any key during this tick). The only argument to this
    // method is a variable that will be filled in with the key that was pressed by the user (if any
    // key was pressed). If the player does hit a key, the argument will be set to one of the
    // following values (constants defined in GameConstants.h):
            // KEY_PRESS_LEFT
            // KEY_PRESS_RIGHT
            // KEY_PRESS_UP
            // KEY_PRESS_DOWN
            // KEY_PRESS_SPACE
            // KEY_PRESS_ESCAPE
            // KEY_PRESS_TAB
            // ‘z’
            // ‘Z’
private:
    // Why am I able to see the GameWorld class?
};
#endif // ACTOR_H_
