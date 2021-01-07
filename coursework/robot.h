#ifndef COURSEWORK_ROBOT_H
#define COURSEWORK_ROBOT_H
#include <vector>
#include "coordination.h"
class robot {
    const int _number;
    const int _team;
    coordination _position;
    int _face;
    int _distance;
public:
    robot(const int &number, const int &team, coordination position): _number(number), _team(team), _position(position), _face(0), _distance(0) {};
    int getNumber() const{ return _number;};
    int getTeam() const{return _team;};
    int getFace() const {return _face;};
    int getDistance() const{return _distance;};
    coordination getPosition(){return _position;};
    void move();
    void turnleft();
    void turnright();
    void printRobot();
private:
    void setPositionX(const int& x){_position.setX(x);};
    void setPositionY(const int& y){_position.setY(y);};
    void setPosition(const int& x, const int&y);
    void setFace(const int& x){_face = x;};
    bool faceNorth() const{return _face == 0;}
    bool faceEast() const{return _face == 1;}
    bool faceSouth() const{return _face == 2;}
    bool faceWest() const{return _face == 3;}
    void moveNorth();
    void moveEast();
    void moveSouth();
    void moveWest();
    void increaseDistance(){++_distance;};
};


#endif //COURSEWORK_ROBOT_H
