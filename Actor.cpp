#include "Actor.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp

#include <iostream>
#include "StudentWorld.h"

void FrackMan::doSomething() {
    StudentWorld* ptr;
    int value = 0;
    ptr->getKey(value);
    switch (value) {
        case KEY_PRESS_UP:
            moveTo(getX(), getY() + 1);
            setDirection(GraphObject::up);
            break;
        case KEY_PRESS_DOWN:
            moveTo(getX(), getY() - 1);
            setDirection(GraphObject::down);
            break;
        case KEY_PRESS_LEFT:
            moveTo(getX() - 1, getY());
            setDirection(GraphObject::left);
            break;
        case KEY_PRESS_RIGHT:
            moveTo(getX() + 1, getY());
            setDirection(GraphObject::right);
            break;
    }
}