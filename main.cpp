#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main()
{
    char input;
    bool Finished = false;
    //Declaring our game as a object of the class TicTacToe
    TicTacToe game;

    //Game Loop
    while (Finished == false) {
        //starts the game by calling it
        game.playGame();
        //output to see if the players want to play again. If Y is input the loop continues, if N is input than the game exits.
        cout << "Would you like to play again? (Y/N): ";
        cin >> input;
        if (input == 'N' || input == 'n') {
            cout<<"Thank You For Playing!"<<endl;
            Finished = true;
        }
    }

    //system("PAUSE");
    return 0;
}
