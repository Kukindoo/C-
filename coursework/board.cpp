#include "board.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void board::showRobots() {
    sortNumber();
    for (int i = 0; i < getVector()->size();++i ){
        printRobot(i);
    }
}

void board::printRobot(int robotIndex) {

        cout << robotList[robotIndex]->getNumber()
             << " " << robotList[robotIndex]->getTeam()
             << " " << robotList[robotIndex]->getPosition().x()
             << " " << robotList[robotIndex]->getPosition().y()
             << "\n";
}

void board::addRobot(robot &myRobot) {
    robotList.push_back(&myRobot);
}

robot *board::getRobot(int serialNumber) {
    for( const auto &x : robotList){
        if(x->getNumber() == serialNumber){

            return x;
        }
    }
    return nullptr;
}

void board::within(int diameter) const {
    for(auto p = robotList.begin(); p != robotList.end();++p) {
        if((**p).getPosition().distanceBetween(coordination(0,0)) <= diameter)
            (**p).printRobot();
    }
}

void board::smartMove(int serialNumber) {
    for(auto p = robotList.begin(); p != robotList.end();++p) {
        if((**p).getNumber() == serialNumber){
            robot* myRobot = *p;
            if((**p).getFace() == 0){
                coordination nextStep =  coordination(( (**p).getPosition().x() + 1) ,
                                                      ((**p).getPosition().y() ) );
                pathCheck(myRobot,nextStep);
            }
            if((**p).getFace() == 1){
                coordination nextStep =  coordination(( (**p).getPosition().x()),
                                                         ((**p).getPosition().y() +1) );
                pathCheck(myRobot,nextStep);
            }
            if((**p).getFace() == 2){
                coordination nextStep =  coordination(( (**p).getPosition().x() - 1) ,
                                                      ((**p).getPosition().y() ) );
                pathCheck(myRobot,nextStep);
            }
            if((**p).getFace() == 3){
                coordination nextStep =  coordination(( (**p).getPosition().x()) ,
                                                      ((**p).getPosition().y() - 1 ) );
                pathCheck(myRobot,nextStep);
            }
        }
    }
}
void board::pathCheck(robot *myRobot, coordination nextStep) {
    if( isEmptySpace( nextStep ) ){
        (*myRobot).move();
    }else{
        for( auto &x : robotList){
            if(x->getPosition().comparePosition(nextStep )) {
                if( (*myRobot).getTeam() != x->getTeam() ){
                    (*myRobot).move();
                    destroyRobot(x->getNumber());
                }
                break;
            }
        }
    }
}

bool board::isEmptySpace(coordination pos) const {
    for(auto p = robotList.begin(); p != robotList.end();++p) {
        if( (**p).getPosition().x() == pos.x() ){
            if( (**p).getPosition().y() == pos.y() )
                return false;
        }
    }
    return true;
}

void board::destroyRobot(int serialNumber) {
    for(int p = 0; p < robotList.size(); ++p) {
        if( robotList[p]->getNumber()== serialNumber ) {
            removeFromList(p);}
        }
    }


void board::removeFromList(int index) {
    delete &getVector()[index];
    *getVector()->erase(getVector()->begin() + index);
}

board::board() {
    //cout << "address of my robotList vector is: " << &robotList <<"\n";
    pRobotList = &robotList;
    //cout << "My pointer is: " << pRobotList <<"\n";
}

void board::travelled() {
    sort(robotList.begin(),robotList.end(), [](robot *a , robot * b){
        if(a->getDistance() == b->getDistance()){
            return a->getNumber() < b->getNumber();
        }else
        return a->getDistance() > b->getDistance();
    });
    for (int i = 0; i < getVector()->size();++i ){
        printTravelledRobot(i);
    }
}

void board::sortNumber() {
    sort(robotList.begin(),robotList.end(), [](robot *a , robot * b){
        return a->getNumber() < b->getNumber();
    });
}

void board::printTravelledRobot(int robotIndex) {
    cout << robotList[robotIndex]->getNumber()
         << " " << robotList[robotIndex]->getDistance()
         << "\n";
}

board::~board() {
    while(!pRobotList->empty()){
        delete &getVector()[getVector()->size()-1];
        *getVector()->erase(getVector()->begin() + (getVector()->size()-1));
    }
    delete pRobotList;
}










