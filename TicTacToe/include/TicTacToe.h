#include<string>
using namespace std;
struct PlayerInfo{

    int score;
    string name;

    };
class TicTacToe
{
public:
    //Constructor
    TicTacToe();
    //Destructor
    ~TicTacToe();
    void play();
    int getX();
    int getY();
    //bool CountScore(char currentPlayer);
    bool PlayAgain();
    bool placeMarker(int x, int y, char currentPlayer);
    bool Victory(char currentPlayer);
    //Empties the board
    void clear();
    // Prints the board
    void print();
    //Stores the state of the board
    char board[3][3];

private:
;
};
