#include <bits/stdc++.h>

using Vec2D = std::vector<std::vector<char>>;
using Vec1D = std::vector<char>;
using Move = std::pair<int,int>;

class TreeNode{

};

class MCTS{

};

class Board{
    Board(){

    }

    Board(Vec2D board){

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

    std::ostream& operator<< (std::ostream &out, Board const& data){

    }
private:
    char player_1 = 'x';
    char player_2 = 'o';
    char empty_square = '.';
};

int main(){

    return 0;
}