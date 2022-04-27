#include <bits/stdc++.h>

using namespace std;

struct Move{
    int row;
    int col;
};

char check(vector<vector<char> > gs){
    // Check if player wins
    if (gs[0][0] != '-')
    {
        bool vert = (gs[0][0] == gs[1][0]) && (gs[0][0] == gs[2][0]);
        bool hort = (gs[0][0] == gs[0][1]) && (gs[0][0] == gs[0][2]);
        if (vert || hort)
        {
            return gs[0][0];
        }
    }
    if (gs[1][1] != '-')
    {
        bool diag1 = (gs[1][1] == gs[0][0]) && (gs[1][1] == gs[2][2]);
        bool diag2 = (gs[1][1] == gs[0][2]) && (gs[1][1] == gs[2][0]);
        bool vert = (gs[1][1] == gs[0][1]) && (gs[1][1] == gs[2][1]);
        bool hort = (gs[1][1] == gs[1][0]) && (gs[1][1] == gs[1][2]);
        if (diag1 || diag2 || vert || hort)
        {
            return gs[1][1];
        }
    }
    if (gs[2][2] != '-')
    {
        bool vert = (gs[2][2] == gs[0][2]) && (gs[2][2] == gs[1][2]);
        bool hort = (gs[2][2] == gs[2][1]) && (gs[2][2] == gs[2][0]);
        if (vert || hort)
        {
            return gs[2][2];
        }
    }
    // Check if board's filled
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (gs[row][col] == '-')
            {
                return '-';
            };
        }
    }
    
    return 'd';
}

class GameState
{
public:
    GameState()
    {
        board.resize(3, vector<char>(3));
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                board[row][col] = '-';
            }
        }
        xToMove = true;
    }

    bool isDone()
    {
        char result = check(board);
        if(result == '-')
            return false;
        
        switch(result){
            case 'x':
                cout << "Player X Wins!\n";
                break;
            case 'o':
                cout << "Player O Wins!\n";
                break;
            case 'd':
                cout << "Draw!\n";
                break;
        }
        return true;
    }

    void move(int r, int c)
    {
        try
        {
            if (board[r - 1][c - 1] == '-')
            {
                if (xToMove)
                {
                    board[r - 1][c - 1] = 'x';
                }
                else
                {
                    board[r - 1][c - 1] = 'o';
                }
                xToMove = !xToMove;
            }
            else
            {
                cout << "Invalid Move\n";
            }
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << "\n";
            cout << "Illegal move\n";
        }
    }

    void display()
    {
        for (int row = 0; row < 3; row++)
        {
            cout << " ";
            for (int col = 0; col < 3; col++)
            {
                char square = board[row][col];
                if (square != '-')
                {
                    cout << square;
                }
                else
                {
                    cout << " ";
                }
                if (col < 2)
                {
                    cout << " | ";
                }
            }
            cout << " ";
            if (row < 2)
            {
                cout << "\n-----------";
            }
            cout << "\n";
        }
    }

    bool isXTurn()
    {
        return xToMove;
    }

    vector<vector<char> > getBoard()
    {
        return board;
    }

private:
    // const int dim = 3;
    vector<vector<char> > board;
    bool xToMove;
};

class MiniMax{
public:
    MiniMax(){

    }

    Move getBestMove(vector<vector<char> > &board, bool isMaximizing){
        int bestScore = (isMaximizing) ? numeric_limits<int>::min() : numeric_limits<int>::max();
        Move optimal;
        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 3; col++){
                if(board[row][col] == '-'){
                    if(isMaximizing){
                        board[row][col] = 'x';
                    } else {
                        board[row][col] = 'o';
                    }
                    int score = evaluate(board, !isMaximizing);
                    board[row][col] = '-';
                    if(isMaximizing){
                        if(score > bestScore){
                            bestScore = score;
                            optimal = {row + 1, col + 1};
                        }
                    } else {
                        if(score < bestScore){
                            bestScore = score;
                            optimal = {row + 1, col + 1};
                        }
                    }
                }
            }
        }
        return optimal;
    }

private:
    int evaluate(vector<vector<char> > &board, bool isMaximizing){
        if(check(board) == 'x'){
            return 1;
        } else if (check(board) == 'o'){
            return -1;
        } else if (check(board) == 'd'){
            return 0;
        }
        
        int bestScore = (isMaximizing) ? numeric_limits<int>::min() : numeric_limits<int>::max();
        
        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 3; col++){
                if(board[row][col] == '-'){
                    if(isMaximizing){
                        board[row][col] = 'x';
                    } else {
                        board[row][col] = 'o';
                    }
                    int score = evaluate(board, !isMaximizing);
                    board[row][col] = '-';
                    if(isMaximizing){
                        if(score > bestScore){
                            bestScore = score;
                        }
                    } else {
                        if(score < bestScore){
                            bestScore = score;
                        }
                    }
                }
            }
        }
        return bestScore;
    }
};

int main()
{
    GameState gs;
    int choice;
    MiniMax mm;

    while (!gs.isDone())
    {
        // if (gs.isXTurn())
        // {
        //     cout << "X to ";
        // }
        // else
        // {
        //     cout << "O to ";
        // }

        // cout << "Move (Format: row col)\n";
        // int r, c;
        // cin >> r >> c;
        // gs.move(r, c);
        // gs.display();
        // cout << "\n";

        if (!gs.isXTurn())
        {
            cout << "O to Move\n";
            vector<vector<char> > board = gs.getBoard();
            bool turn = gs.isXTurn();
            Move m = mm.getBestMove(board, turn);
            gs.move(m.row, m.col);
            
        }
        else
        {
            cout << "X to Move (Format: row col)\n";
            int r, c;
            cin >> r >> c;
            gs.move(r, c);
        }

        // if(gs.isXTurn()){
        //     cout << "X to Move\n";
        // } else {
        //     cout << "O to Move\n";
        // }

        // vector<vector<char> > board = gs.getBoard();
        // bool turn = gs.isXTurn();
        // Move m = bestMove(board, turn);
        // gs.move(m.row, m.col);

        gs.display();
    }
    return 0;
}