//
// Created by jakub on 20/11/2020.
//

#ifndef COURSEWORK_GAME_H
#define COURSEWORK_GAME_H
#include "board.h"
#include <string>
#include <vector>
#include <iostream>

class game {
    std::vector<std::string> projectFiles;
    board myBoard;
public:
    game();
    std::vector<std::string> split_space(const std::string &s);
    void setStartFile(std::string filename);
    void setCommandFile(std::string filename);
    std::string getStartFile();
    std::string getCommandFile();
    void openStartFile(std::string filename);
    void openCommandFile(std::string filename);
    void openFile(std::string filename);
    void processStartFile(std::ifstream &streamName);
    void processCommandFile(std::ifstream &streamName);
    board getBoard(){return myBoard;};
    bool isStartfileTest(std::string filename);
};


#endif //COURSEWORK_GAME_H
