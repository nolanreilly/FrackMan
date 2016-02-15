#include "Actor.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp

#include "StudentWorld.h"

void FrackMan::doSomething() {
    int keyValue;
    if(accessGetKey()->getKey(keyValue)) {
        switch (keyValue) {
            case KEY_PRESS_UP:
                setDirection(GraphObject::up);
                moveTo(getX(), getY() + 1);
                clearDirt(getX(), getY() + 3, 'u');
                break;
            case KEY_PRESS_DOWN:
                setDirection(GraphObject::down);
                moveTo(getX(), getY() - 1);
                clearDirt(getX(), getY(), 'd');
                break;
            case KEY_PRESS_LEFT:
                setDirection(GraphObject::left);
                moveTo(getX() - 1, getY());
                clearDirt(getX(), getY(), 'l');
                break;
            case KEY_PRESS_RIGHT:
                setDirection(GraphObject::right);
                moveTo(getX() + 1, getY());
                clearDirt(getX() + 3, getY(), 'r');
                break;
        }
    }
}

void FrackMan::clearDirt(int x, int y, char dir) {
    if((!accessGetKey()->getDirtArr(x, y)->getDoneDiggity())) {
        //accessGetKey()->getDirtArr(x, y)->setDoneDiggity(true);
        switch(dir) {
            case 'u':
                accessGetKey()->getDirtArr(x, y)->setVisible(false);
                accessGetKey()->getDirtArr(x+1, y)->setVisible(false);
                accessGetKey()->getDirtArr(x+2, y)->setVisible(false);
                accessGetKey()->getDirtArr(x+3, y)->setVisible(false);
                break;
            case 'd':
                accessGetKey()->getDirtArr(x, y)->setVisible(false);
                accessGetKey()->getDirtArr(x+1, y)->setVisible(false);
                accessGetKey()->getDirtArr(x+2, y)->setVisible(false);
                accessGetKey()->getDirtArr(x+3, y)->setVisible(false);
                break;
            case 'l':
                accessGetKey()->getDirtArr(x, y)->setVisible(false);
                accessGetKey()->getDirtArr(x, y+1)->setVisible(false);
                accessGetKey()->getDirtArr(x, y+2)->setVisible(false);
                accessGetKey()->getDirtArr(x, y+3)->setVisible(false);
                break;
            case 'r':
                accessGetKey()->getDirtArr(x, y)->setVisible(false);
                accessGetKey()->getDirtArr(x, y+1)->setVisible(false);
                accessGetKey()->getDirtArr(x, y+2)->setVisible(false);
                accessGetKey()->getDirtArr(x, y+3)->setVisible(false);
                break;
        }

    }
}

// void FrackMan::canMove(int x, int y) {}

