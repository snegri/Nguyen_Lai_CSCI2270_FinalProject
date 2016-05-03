#include "TicTacToe.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
TicTacToe::TicTacToe()
{
}
TicTacToe::~TicTacToe()
{
}
//To play the game!
void TicTacToe::play()
{
    clear();
    //Assigns players to a marker
    char playerX = 'X';
    char playerO = 'O';
    //Sets the first player to player1
    char currentPlayer = playerX;
    //Tells the game it is not over
    bool Finished = false;
    bool info = false;
    int x, y;
    //Declares and sets turn counter to 0, since once the turn hits 9 the game is over
    int turn = 0;

    //loop for the game
    while (Finished == false) {
        //the below line makes it so you see nothing but the board and relevant prompts
        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
        std::cout << "Player " << currentPlayer << "'s turn!" << std::endl;
        //the above let's the players know who's turn it is

        //Print out the board
        print();

        //Calls the functions to get the coordinates
        x = getX();
        y = getY();


        while (placeMarker(x, y, currentPlayer) == false) {
            //Tells the player the spot is not available
            cout << "That spot is occupied!\n";
            x=getX();
            y=getY();
        }
        {
            turn++;
            //Checks if the player has won
            if (Victory(currentPlayer) == true) {
                //prints the final board

                //the below line makes it so you see nothing but the board and relevant prompts
                std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
                print();
                cout << "The game is over! Player " << currentPlayer << " has won!\n";
                //CountScore(currentPlayer);
                Finished = true;
            } else if (turn == 9) {
            //Shows that the game ends in a tie if turn counter hits 9
                cout << "Its a tie game!\n";
                Finished = true;
            }
            // Switches players for each round
            if (currentPlayer == playerX) {
                currentPlayer = playerO;
            } else {
                currentPlayer = playerX;
            }
        }
    }
}
/*bool TicTacToe::CountScore(char currentPlayer)
{
    char playerX;
    char playerO;
    if (currentPlayer == 'X'){
        //playerXscore = playerXscore +1;
        cout<<"hello"<<endl;
        return true;
    }
    else
        //playerOscore = playerOscore +1;
        return false;
}*/
bool TicTacToe::PlayAgain()
{   char input;
    //bool Finished = false;
    cout << "Would you like to play again? (Y/N): ";
    cin >> input;
    if (input == 'N' || input == 'n') {
        cout << std::endl << "Thank You For Playing!" << endl;
        //Finished = true;
        return true;
        }
    else{
        return false;
    }
}


int TicTacToe::getX()
{
    bool input = true;

    int x;

    while (input == true) {
        cout << "Where do you want to place your marker? "<<endl;
        cout << "Enter the X coordinate: ";
        cin >> x;

        if (x < 0 || x > 2) {
            cout << "Invalid Coordinate!\n";
        } else {
            input= false;
        }
    }
    return x ;
}

int TicTacToe::getY()
{
    bool input = true;

    int y;

    while (input== true) {
        cout << "Enter the Y coordinate: ";
        cin >> y;

        if (y < 0 || y > 2) {
            cout << "Invalid Input! \n";
        } else {
            input = false;
        }
    }
    return y ;
}

bool TicTacToe::placeMarker(int x, int y, char currentPlayer)
{
    if (board[y][x] != ' ') {
        return false;
    }

    board[y][x] = currentPlayer;
    return true;
}

bool TicTacToe::Victory(char currentPlayer)
{
    //Check the rows
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            return true;
        }
    }

    //Check the columns
    for (int i = 0; i < 3; i++) {
        if ((board[0][i] == currentPlayer) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            return true;
        }
    }

    //Check top left diagonal
    if ((board[0][0] == currentPlayer) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        return true;
    }

    //Check top right diagonal
    if ((board[2][0] == currentPlayer) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) {
        return true;
    }

    return false;
}

void TicTacToe::clear()
{
    //Clears the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void TicTacToe::print()
{

    cout << endl;
    cout << " |0 1 2|\n";
    for (int i = 0; i < 3; i++) {
        cout << " -------\n";
        cout << i << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|\n";
    }
    cout << " -------\n";
}
