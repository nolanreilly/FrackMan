#include "Actor.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp

#include "StudentWorld.h"

FrackMan::~FrackMan() {
    delete accessGetKey()->getFrack();
}

void FrackMan::doSomething() {
    int keyValue;
    if(accessGetKey()->getKey(keyValue)) {
        switch (keyValue) {
            case KEY_PRESS_UP:
                setDirection(GraphObject::up);
                if(canMove(getX(), getY() + 1)) {
                    moveTo(getX(), getY() + 1);
                    clearDirt(getX(), getY() + 3, 'u');
                }
                break;
            case KEY_PRESS_DOWN:
                setDirection(GraphObject::down);
                if(canMove(getX(), getY() - 1)) {
                    moveTo(getX(), getY() - 1);
                    clearDirt(getX(), getY(), 'd');
                }
                break;
            case KEY_PRESS_LEFT:
                setDirection(GraphObject::left);
                if(canMove(getX() - 1, getY())) {
                    moveTo(getX() - 1, getY());
                    clearDirt(getX(), getY(), 'l');
                }
                break;
            case KEY_PRESS_RIGHT:
                setDirection(GraphObject::right);
                if(canMove(getX() + 1, getY())) {
                    moveTo(getX() + 1, getY());
                    clearDirt(getX() + 3, getY(), 'r');
                }
                break;
        }
    }
}

bool FrackMan::canMove(int x, int y) {
    if(x >= 0 && x <= 60 && y >= 0 && y <= 60)
        return true;
    return false;
}

void FrackMan::deleteDirt(int x, int y, char vert_horiz) {
    if(accessGetKey()->getDirt(x, y) != nullptr) {
        for(int i = 0; i < 4; i++) {
            switch(vert_horiz) {
                case 'v':
                    delete accessGetKey()->getDirt(x + i, y);
                    accessGetKey()->setDirtNull(x + i, y);
                    break;
                case 'h':
                    delete accessGetKey()->getDirt(x, y + i);
                    accessGetKey()->setDirtNull(x, y + i);
                    break;
            }
        }
    }
}

void FrackMan::clearDirt(int x, int y, char dir) {
    if(accessGetKey()->getDirt(x, y)) {
        switch(dir) {
            case 'u':
                deleteDirt(x, y, 'v');
                break;
            case 'd':
                deleteDirt(x, y, 'v');
                break;
            case 'l':
                deleteDirt(x, y, 'h');
                break;
            case 'r':
                deleteDirt(x, y, 'h');
                break;
        }
    }
}
