//
// Created by jakub on 20/11/2020.
//

#ifndef COURSEWORK_BOARD_H
#define COURSEWORK_BOARD_H

#include "robot.h"
#include <vector>

class board {
    std::vector<robot*> robotList;
    std::vector<robot*>* pRobotList;
public:
    board();
    void addRobot(robot& myRobot);
    void showRobots();
    robot* getRobot(int serialNumber);
    void destroyRobot( int serialNumber);
    void within(int diameter) const;
    void smartMove(int serialNumber);
    std::vector<robot*>* getVector(){return pRobotList;};
    void travelled();
    void sortNumber();


    virtual ~board();
private:
    void printRobot(int robotIndex);
    void printTravelledRobot(int robotIndex);
    bool isIndexValid(int i){return i >=0;};
    bool isEmptySpace(coordination pos) const;
    void removeFromList(int index);
    void pathCheck(robot * myRobot, coordination nextStep);
};


#endif //COURSEWORK_BOARD_H
