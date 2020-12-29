#include "prettygame.h"

#include <iostream>
#include <vector>

#include "../lib/box.h"
#include "../lib/game.h"
#include "../lib/player.h"

using namespace std;

struct {
    string hor = "───";
    string topMid = "┬";
    string topLeft = "┌";
    string topRight = "┐";
    string btmMid = "┴";
    string btmLeft = "└";
    string btmRight = "┘";
    string ver = "│";
    string leftMid = "├";
    string midMid = "┼";
    string rightMid = "┤";
} Borders;

PrettyGame::PrettyGame() {}
PrettyGame::~PrettyGame() {}

inline int toBoxNumber(int row, int col) {
    return row * 3 + col;
}

bool isOk(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2)
        return false;

    Game* game = Game::instance();
    Box* box = game->currentBoxState(toBoxNumber(row, col));
    return box->player() == nullptr;
}

void PrettyGame::move() {
    Game* game = Game::instance();
    int row = -1;
    int col = -1;

    do {
        cout << game->currentPlayer()->toPrettyString() << " (0-2 0-2): ";
        cin >> row >> col;
    } while (!isOk(row, col));

    game->move(toBoxNumber(row, col));
}

void printRowSep(string left, string mid, string right) {
    cout << left << Borders.hor << mid << Borders.hor << mid << Borders.hor << right << endl;
}

void printRowBox(Box* boxLeft, Box* boxMid, Box* boxRight) {
    cout << Borders.ver << " " << boxLeft->toPrettyString() << " ";
    cout << Borders.ver << " " << boxMid->toPrettyString() << " ";
    cout << Borders.ver << " " << boxRight->toPrettyString() << " ";
    cout << Borders.ver << endl;
}

void PrettyGame::printGame() {
    Game* game = Game::instance();
    vector<Box*> boxes = game->currentState();

    printRowSep(Borders.topLeft, Borders.topMid, Borders.topRight);
    printRowBox(boxes[0], boxes[1], boxes[2]);
    printRowSep(Borders.leftMid, Borders.midMid, Borders.rightMid);
    printRowBox(boxes[3], boxes[4], boxes[5]);
    printRowSep(Borders.leftMid, Borders.midMid, Borders.rightMid);
    printRowBox(boxes[6], boxes[7], boxes[8]);
    printRowSep(Borders.btmLeft, Borders.btmMid, Borders.btmRight);
}

bool PrettyGame::checkForWinner() {
    Game* game = Game::instance();
    Player* winner = game->winnerForTris(game->getTris());

    if (winner) {
        cout << "Il vincitore è: " << winner->toPrettyString() << endl;
        return true;
    } else if (game->isBoardFull()) {
        cout << "Parità!" << endl;
        return true;
    }

    return false;
}

bool PrettyGame::playAgain() {
    char answer;
    do {
        cout << "Vuoi giocare ancora? (y/n) ";
        cin >> answer;
    } while (answer != 'y' && answer != 'n');

    if (answer == 'y')
        Game::newGame();

    return answer == 'y';
}