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
    std::shared_ptr<TreeNode> parent;
    std::unordered_map<std::string, TreeNode> children;

    TreeNode(Board board){
        if (board.isWin() || board.isDraw()){
            this->isTerminal = true;
        } else {
            this->isTerminal = false;
        }

        this->isFullyExpanded = this->isTerminal;
    }

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
public:
    TreeNode root;

    MCTS(){

    }

    TreeNode search(Board initial_state){
        this->root = TreeNode(initial_state);

        for(int i = 0; i < 1000; i++){
            TreeNode node = this->select(this->root);

            int score = this->rollout(node.board);

            this->backpropagate(node, score);
        }

        try {
            return this->getBestMove(this->root, 0);
        } catch (const std::exception& e){
            cout << e.what() << '\n';
        }
    }

    TreeNode select(TreeNode node){
        while(!node.isTerminal){
            if(node.isFullyExpanded){
                node = this->getBestMove(node, 2);
            } else {
                return self.expand(node);
            }
        }

        return node;
    }

    TreeNode expand(TreeNode node){
        std::vector<Board> states = node.board.generateStates();

        for(Board state : states){
            std::string encoded = this->encodePosition(state);
            if (node.children.find(encoded) != node.children.end()){
                TreeNode new_node = TreeNode(state, node);

                node.children[encoded] = new_node;

                if (states.size() == node.children.size()){
                    node.isFullyExpanded = true;
                }

                return new_node;
            }
        }

        cout << "Error has occured\n";
    }

    int rollout(Board board){
        while(!board.isWin()){
            try{
                std::srand(std::time(0));
                std::vector<Board> states = board.generateStates();
                int random_pos = std::rand() % states.size();

                board = states[random_pos];
            } catch {
                return 0;
            }
        }

        if (board.player_2 == 'x'){
            return 1;
        } else if (board.player_2 == 'o'){
            return -1;
        }
    }

    void backpropagate(TreeNode node, int score){
        while(node){
            node.visits++;
            node.score += score;
            node = node.parent;
        }
    }

    TreeNode getBestMove(TreeNode node, double exploration_constant){
        double best_score = std::numeric_limits<double>::min(), move_score;
        std::vector<TreeNode> best_moves;
        int current_player;
        

        for(auto iter = node.children.begin(); iter != node.children.begin(); iter++){
            TreeNode child_node = iter->second;

            if(child_node.board.player_2 == 'x'){
                current_player = 1;
            } else if(child_node.board.player_2 == 'o'){
                current_player = -1;
            }

            move_score = current_player * child_node.score / child_node.visits + 
                         exploration_constant * std::sqrt(std::log(node.visits / child_node.visits));
            
            if move_score > best_score{
                best_score = move_score;
                best_moves.clear();
                best_moves.push_back(child_node);
            } else if (move_score == best_score){
                best_moves.push_back(child_node);
            }
        }

        std::srand(std::time(0));
        std::vector<Board> states = board.generateStates();
        int random_pos = std::rand() % states.size();

        return best_moves[random_pos];
    }

    std::string encodePosition(Board board){
        std::string out = "";
        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 3; col++){
                out += board.position[row][col];
            }
        }
        return out;
    }

private:

};

int main(){
    Board board;
    board.gameLoop();
    // board.printBoard();

    return 0;
}