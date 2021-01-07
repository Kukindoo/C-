//
// Created by jakub on 01/12/2020.
//

#ifndef COURSEWORK_COORDINATION_H
#define COURSEWORK_COORDINATION_H


class coordination {
    int positionX;
    int positionY;
public:
    coordination(const int& x, const int& y) : positionX(x), positionY(y) {};
    int x(){return positionX;};
    int y(){return positionY;};
    void setX( const int &pos) {positionX = pos;};
    void setY( const int &pos) {positionY = pos;};
    void printCord();
    bool comparePosition(const coordination &pos);
    int distanceBetween(const coordination &pos) const;
};



#endif //COURSEWORK_COORDINATION_H
