#ifndef ACTOR_H_
#define ACTOR_H_
#include "GraphObject.h"
#include "GameConstants.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class StudentWorld;

class Dirt: public GraphObject {
public:
    Dirt(int x, int y): GraphObject(IID_DIRT, x, y, right, 0.25) {
        setVisible(true);
        m_doneDiggity = false;
    }
    bool getDoneDiggity() const {
        return m_doneDiggity;
    }
    void setDoneDiggity(bool doneDiggity) {
        m_doneDiggity = doneDiggity;
    }
private:
    bool m_doneDiggity;
};

class Actor: public GraphObject {
public:
    Actor(int IID, int x, int y, StudentWorld* p_world): GraphObject(IID, x, y), m_accessGetKey(p_world) {
        setVisible(true);
        m_health = 100;
    }
    ~Actor() {
        setVisible(false);
        
    }
    int getHealth() const {
        return m_health;
    }
    StudentWorld* accessGetKey() const {
        return m_accessGetKey;
    }
    virtual void doSomething() = 0;
    
    virtual bool canMove(int x, int y) = 0;
    
private:
    int m_health;
    StudentWorld* m_accessGetKey;
};

class FrackMan: public Actor
{
public:
    FrackMan(StudentWorld* p_world): Actor(IID_PLAYER, 30, 60, p_world)
    {}
    ~FrackMan()
    {}
    virtual void doSomething();
    virtual bool canMove(int x, int y);
    
    void clearDirt(int x, int y, char dir);
};
#endif // ACTOR_H_
