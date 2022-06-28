#include <bits/stdc++.h>

using Vec2D = std::vector<std::vector<char>>;
using Vec1D = std::vector<char>;
using Move = std::pair<int,int>;

// class TreeNode{

// };

// class MCTS{

// };

class Board{
public:
    char player_1 = 'x';
    char player_2 = 'o';
    char empty_square = '.';

    Vec2D position;

    Board(){
        this->position = Vec2D(3, Vec1D(3, '.'));
    }

    Board(const Board& board){

    }

    Vec2D makeMove(int row, int col){
        return Vec2D();
    }

    bool isDraw(){
        return false;
    }

    bool isWin(){
        return false;
    }

    std::vector<Move> generateStates(){
        return std::vector<Move>();
    }

    void gameLoop(){

    }

    void printBoard(){
        std::string out = "";
        if(this->player_1 == 'x'){
            std::cout << "\n-------------\n\"x\" to move:\n-------------\n\n";
        } else if(this->player_2 == 'o'){
            std::cout << "\n-------------\n\"x\" to move:\n-------------\n\n";
        }

        for (int row = 0; row < 3; row++){
            for (int col = 0; col < 3; col++){
                std::cout << " " << this->position[row][col];
            }
            std::cout << "\n";
        }
    }
};

int main(){
    Board board;

    board.printBoard();

    board.position[1][1] = 'x';

    Board board1(board);

    board1.printBoard();
    return 0;
}