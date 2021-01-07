#include "robot.h"
#include "game.h"
using namespace std;
int main() {
    game robotGame;
    robotGame.setStartFile("start.txt");
    robotGame.setCommandFile("commands.txt");
    robotGame.openStartFile(robotGame.getStartFile());
    robotGame.openCommandFile(robotGame.getCommandFile());
}
