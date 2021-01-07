//
// Created by jakub on 20/11/2020.
//

#include "game.h"
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

game::game() {
    projectFiles.push_back("");
    projectFiles.push_back("");
}

vector<string> game::split_space(const string &s) {
    vector<string> v;
    auto space = find(s.cbegin(), s.cend(), ' ');
    v.push_back(string(s.cbegin(), space));
    while (space != s.cend()) {
        auto start = ++space;
        space = find(start, s.cend(), ' ');
        v.push_back(string(start, space));
    }
    return v;
}

string game::getStartFile(){
    return projectFiles[0];
}
std::string game::getCommandFile() {
    return projectFiles[1];
}

void game::setStartFile(std::string filename) {
    projectFiles[0] = filename;
}

void game::setCommandFile(std::string filename) {
    projectFiles[1] = filename;
}
void game::openStartFile(std::string filename) {
    if(isStartfileTest(filename)){
        openFile(filename); }
    else{
        cout << filename << " is not in correct format"; }
}
void game::openCommandFile(std::string filename) {
    openFile(filename);
}

void game::openFile(std::string filename) {
    ifstream openFile;
    openFile.open(filename);
    if(openFile.is_open()){
        if(isStartfileTest(filename)){
            processStartFile(openFile);
        }else{
            processCommandFile(openFile);
        }
        openFile.close();
    }else{
        cout << "Failed open file!\n";
    }
}

void game::processStartFile(ifstream &streamName) {
    string line;
    vector<string> splittedString;
        while (getline(streamName, line)) {

            splittedString = split_space(line);
            int number = stoi(splittedString[0]);
            int team = stoi(splittedString[1]);
            coordination* pos = new coordination(stoi(splittedString[2]), stoi(splittedString[3]));

            //myBoard.existence(*pos);
            robot* myRobot = new robot(number,team,*pos);
            myBoard.addRobot(*myRobot);
        }
}

void game::processCommandFile(ifstream &streamName) {
    string line;
    vector<string> splittedString;
    while (getline(streamName, line)) {
        splittedString = split_space(line);
        if(splittedString.size() == 1){
            if( splittedString[0] == "show"){
                myBoard.showRobots();
            }
            if(splittedString[0] == "travelled"){
                myBoard.travelled();
            }
        } else {
            if(splittedString[0] == "within"){
                myBoard.within(stoi(splittedString[1]));
            }
            if(splittedString[0] == "turnleft"){
                myBoard.getRobot(stoi(splittedString[1]))->turnleft();
            }
            if(splittedString[0] == "turnright"){
                myBoard.getRobot(stoi(splittedString[1]))->turnright();
            }
            if(splittedString[0] == "move"){
                myBoard.smartMove(stoi(splittedString[1]));
            }
        }
    }
}

bool game::isStartfileTest(std::string filename) {
    ifstream testStream;
    string testString;
    testStream.open(filename);
    if(testStream.is_open())
        //cout<<"test is open\n";
    getline(testStream,testString);
    testStream.close();
    return count(testString.cbegin(), testString.cend(), ' ')>2;
}













