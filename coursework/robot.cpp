#include "robot.h"
#include <iostream>
using namespace std;

void robot::turnleft() {
    if(getFace() == 0)
        setFace(4);
    setFace(((getFace() - 1)%4));
}
void robot::turnright() {
    setFace((getFace() + 1)%4);
}

void robot::move() {
    increaseDistance();
    if(faceNorth()){
        moveNorth();
    }
    if(faceEast()){
        moveEast();
    }
    if(faceSouth()){
        moveSouth();
    }
    if(faceWest()){
        moveWest();
    }
}

void robot::printRobot() {
    cout << getNumber()
         << " " << getTeam()
         << " " << getPosition().x()
         << " " << getPosition().y()
         << " " << getFace()
         << " " << getDistance()
         << "\n";
}

void robot::setPosition(const int &x, const int &y) {
    setPositionX(x);
    setPositionY(y);
}

void robot::moveNorth() {
    setPositionX((getPosition().x() + 1));
}

void robot::moveEast() {
    setPositionY((getPosition().y() + 1));
}

void robot::moveSouth() {
    setPositionX((getPosition().x() - 1));
}

void robot::moveWest() {
    setPositionY((getPosition().y() - 1));
}







