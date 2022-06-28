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

    Board(const Board& board):
        player_1(board.player_1),
        player_2(board.player_2),
        position(board.position){

    }

    Board makeMove(int row, int col){
        Board tmpBoard(*this);
        tmpBoard.position[row][col] = this->player_1;

        // Bit manipulation magic
        tmpBoard.player_1 ^= tmpBoard.player_2;
        tmpBoard.player_2 = tmpBoard.player_1 ^ tmpBoard.player_2;
        tmpBoard.player_1 ^= tmpBoard.player_2;

        return tmpBoard;
    }

    bool isDraw(){
        for(auto &row: this->position){
            for(auto &square: row){
                if(square == this->empty_square)
                    return false;
            }
        }
        return true;
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
        } else if(this->player_1 == 'o'){
            std::cout << "\n-------------\n\"o\" to move:\n-------------\n\n";
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

    board.position[0][0] = 'o';
    board.position[0][1] = 'x';
    board.position[0][2] = 'x';
    board.position[1][0] = 'o';
    board.position[1][1] = 'x';
    board.position[1][2] = 'x';
    board.position[2][0] = 'o';
    board.position[2][1] = 'x';
    board.position[2][2] = 'x';

    board.printBoard();


    std::cout << board.isDraw() << "\n";
    return 0;
}