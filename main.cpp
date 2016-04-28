#include <iostream>
#include<string>
#include "TicTacToe.h"

using namespace std;

int main()
{

    bool Finished = false;
    int playerXscore = 0;
    int playerOscore = 0;
    char currentPlayer;
    //Declaring our game as a object of the class TicTacToe
    TicTacToe game;

    //Game Loop
    while (Finished == false) {
        //starts the game by calling it
        game.play();
        /*if (game.CountScore(currentPlayer) == true){
            playerXscore = playerXscore+1;
        }
        else{
            playerOscore = playerOscore+1;
        }
        cout<<"Player X's score is: " << playerXscore<<endl;
        cout<<"Player O's score is: " << playerOscore<<endl;*/
        //call PlayAgain to see if the players want to play again
        if (game.PlayAgain() == true)
        {
            Finished = true;
        }
        else{
            Finished = false;
        }

    }
    return 0;
}
