#include <bits/stdc++.h>

using Vec2D = std::vector<std::vector<char>>;
using Vec1D = std::vector<char>;
using Move = std::pair<int,int>;

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

    // Returns board object
    Board makeMove(int row, int col){
        Board tmpBoard(*this);
        tmpBoard.position[row][col] = this->player_1;

        // Bit manipulation magic
        tmpBoard.player_1 ^= tmpBoard.player_2;
        tmpBoard.player_2 = tmpBoard.player_1 ^ tmpBoard.player_2;
        tmpBoard.player_1 ^= tmpBoard.player_2;

        return tmpBoard;
    }

    // Checks to see if state is drawn
    bool isDraw(){
        for(auto &row: this->position){
            for(auto &square: row){
                if(square == this->empty_square)
                    return false;
            }
        }
        return true;
    }

    // Checks to see if player 2 has won
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


    // Generates all possible board states from current state
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

    // Runs the game loop
    void gameLoop(){
        this->printBoard();

        while(true){
            int row, col;
            std::cout << "> ";
            std::cin >> row >> col;
            std::cout << "\n";

            try{
                if(this->position[row][col] != this->empty_square){
                    std::cout << "Illegal move\n";
                    continue;
                }

                *this = this->makeMove(row, col);
                
                this->printBoard();

                if (this->isWin()){
                    printf("Player \"%c\" has won the game!", this->player_2);
                    break;
                } else if (this->isDraw()){
                    printf("Draw!");
                    break;
                }

            } catch (std::exception& e){
                std::cout << "Error: " << e.what() << "\nIllegal move\n";
                break;
            }
        }
    }

    // Prints the board to command line
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

class TreeNode{
public:
    int visits = 0, score = 0;
    Board board;
    bool isTerminal, isFullyExpanded;
    TreeNode parent;
    std::unordered_map<int, int> children;

    TreeNode(Board board, TreeNode parent){
        if (board.isWin() || board.isDraw()){
            this->isTerminal = true;
        } else {
            this->isTerminal = false;
        }

        this->isFullyExpanded = this->isTerminal;

        this->parent = parent;
    }
};

class MCTS{
    MCTS(){

    }

    Board search(Board initial_state){

    }

    TreeNode expand(TreeNode node){

    }

    TreeNode expand(TreeNode node){

    }

    int rollout(Board board){

    }

    void backpropagate(TreeNode node, int score){

    }

    TreeNode getBestMove(TreeNode node, double exploration_constant){
        
    } 

};

int main(){
    Board board;
    board.gameLoop();
    // board.printBoard();

    return 0;
}