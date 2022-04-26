#include <bits/stdc++.h>

using namespace std;

struct Move{
    int x;
    int y;
};

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

int main()
{
    GameState gs;
    int choice;

    while (!gs.isDone())
    {
        if (gs.isXTurn())
        {
            cout << "X to ";
        }
        else
        {
            cout << "O to ";
        }

        cout << "Move (Format: row col)\n";
        int r, c;
        cin >> r >> c;
        gs.move(r, c);
        gs.display();
        cout << "\n";
    }
    return 0;
}