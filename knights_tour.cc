#include <bits/stdc++.h>
using namespace std;

#define knightsMoves 8
int possibleMovesX[8] = {-1, -1, -2, -2, 1, 1, 2, 2};
int possibleMovesY[8] = {2, -2, 1, -1, 2, -2, -1, 1};

int isMovePossible(int x, int y, int chessboard[knightsMoves][knightsMoves])
{
    return (x >= 0 && x < knightsMoves && y >= 0 && y < knightsMoves && chessboard[x][y] == -1);
}

void solution(int chessboard[knightsMoves][knightsMoves])
{
    for (int x = 0; x < knightsMoves; x++) {
        for (int y = 0; y < knightsMoves; y++)
            cout << " " << setw(2) << chessboard[x][y] << " ";
        cout << endl;
    }
}

int solve(int x, int y, int moves, int chessboard[knightsMoves][knightsMoves], int possibleMovesX[knightsMoves], int possibleMovesY[knightsMoves])
{
    int i, nextX, nextY;
    if (moves == knightsMoves * knightsMoves){
        return 1;
    }

    for (i = 0; i < 8; i++) {
        nextX = x + possibleMovesX[i];
        nextY = y + possibleMovesY[i];
        if (isMovePossible(nextX, nextY, chessboard)) {
            chessboard[nextX][nextY] = moves;
            if (solve(nextX, nextY, moves + 1, chessboard, possibleMovesX, possibleMovesY)
                == 1)
                return 1;
            else

                chessboard[nextX][nextY] = -1;
        }
    }
    return 0;
}

int main()
{
    int chessboard[knightsMoves][knightsMoves];

    for(int x = 0; x < knightsMoves; x++){
        for(int y = 0; y < knightsMoves; y++){
            chessboard[x][y] = -1;
        }
    }
    chessboard[0][0] = 0;

    if(solve(0, 0, 1, chessboard, possibleMovesX, possibleMovesY) == 0){
        cout << "Solution does not exist";
        return 0;
    }
    else {
        solution(chessboard);
    }
    return 1;
    return 0;
}
