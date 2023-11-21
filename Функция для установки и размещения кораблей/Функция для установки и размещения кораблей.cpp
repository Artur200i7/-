#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int BOARD_SIZE = 10;
const char EMPTY = '-';
const char SHIP = '+';
const char MISS = 'O';
const char HIT = 'X';

struct Ship {
    int size;
    int hits;
    bool sunk;
};

struct Player {
    char board[BOARD_SIZE][BOARD_SIZE];
    char visibleBoard[BOARD_SIZE][BOARD_SIZE];
    Ship ships[10];
};

void setupComputerShips(Player& computer) {
    srand(time(0) + 1);

    int shipSizes[10] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };

    for (int i = 0; i < 10; ++i) {
        computer.ships[i].size = shipSizes[i];
        computer.ships[i].hits = 0;
        computer.ships[i].sunk = false;
    }

    for (int i = 0; i < 10; ++i) {
        bool placed = false;
        while (!placed) {
            int row = rand() % BOARD_SIZE;
            int col = rand() % BOARD_SIZE;
            char direction = (rand() % 2 == 0) ? 'H' : 'V';

            if (isValidPlacement(computer.board, row, col, computer.ships[i].size, direction)) {
                placeShip(computer.board, row, col, computer.ships[i].size, direction);
                placed = true;
            }
        }
    }
}
[16:42]
void computerMove(char playerBoard[BOARD_SIZE][BOARD_SIZE]) {
    int row, col;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (playerBoard[row][col] == HIT || playerBoard[row][col] == MISS);

    makeMove(playerBoard, row, col);
}