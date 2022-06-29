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
        this->position = Vec2D(3, Vec1D(3, this->empty_square));
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
        for(int i = 0; i < 3; i++){
            if ((this->position[0][i] == this->player_2) &&
                (this->position[1][i] == this->player_2) &&
                (this->position[2][i] == this->player_2)){
                return true;
            }

            if ((this->position[i][0] == this->player_2) &&
                (this->position[i][1] == this->player_2) &&
                (this->position[i][2] == this->player_2)){
                return true;
            }
        }

        bool diag_1 = (this->position[0][0] == this->player_2) &&
                      (this->position[1][1] == this->player_2) &&
                      (this->position[2][2] == this->player_2);

        bool diag_2 = (this->position[2][0] == this->player_2) &&
                      (this->position[1][1] == this->player_2) &&
                      (this->position[0][2] == this->player_2);

        return diag_1 || diag_2;
    }

    std::vector<Board> generateStates(){
        std::vector<Board> actions;
        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 3; col++){
                if(this->position[row][col] == this->empty_square){
                    actions.push_back(this->makeMove(row, col));
                }
            }
        }

        return actions;
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

    board = board.makeMove(1,1);

    board.printBoard();

    auto actions = board.generateStates();

    for(auto action : actions){
        action.printBoard();
    }

    std::cout << board.player_2 << "\t" << board.isWin() << "\n";
    return 0;
}