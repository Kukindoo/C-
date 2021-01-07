//
// Created by jakub on 01/12/2020.
//

#include "coordination.h"
#include <iostream>
using namespace std;
void coordination::printCord(){
    cout << "x: " << x() << " y: " << y() << ".\n";

}

bool coordination::comparePosition(const coordination &pos) {
    return (pos.positionX == positionX) && (pos.positionY == positionY) ;
}

int coordination::distanceBetween(const coordination &pos) const{
    return abs(positionX - pos.positionX) + abs(positionY - pos.positionY);
}
