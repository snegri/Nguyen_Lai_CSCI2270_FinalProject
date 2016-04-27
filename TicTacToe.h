#pragma once
class TicTacToe
{
public:
    //Constructor
    TicTacToe();
    //This plays the game
    void playGame();
    //Gets input from the user
    int getX();
    int getY();
    //Places the marker.
    bool placeMarker(int x, int y, char currentPlayer);
    //Returns true if the current player won!
    bool Victory(char currentPlayer);
    //Empties the board
    void clear();
    // Prints the board
    void print();
    //Stores the board state
    char board[3][3];

private:
;
};
