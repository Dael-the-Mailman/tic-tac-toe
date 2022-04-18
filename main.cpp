#include <bits/stdc++.h>

using namespace std;

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
        // Check if player wins
        if (board[0][0] != '-')
        {
            bool vert = (board[0][0] == board[1][0]) && (board[0][0] == board[2][0]);
            bool hort = (board[0][0] == board[0][1]) && (board[0][0] == board[0][2]);
            if (vert || hort)
            {
                cout << "Player " << board[0][0] << " Wins!\n";
                return true;
            }
        }
        if (board[1][1] != '-')
        {
            bool diag1 = (board[1][1] == board[0][0]) && (board[1][1] == board[2][2]);
            bool diag2 = (board[1][1] == board[0][2]) && (board[1][1] == board[2][0]);
            bool vert = (board[1][1] == board[0][1]) && (board[1][1] == board[2][1]);
            bool hort = (board[1][1] == board[1][0]) && (board[1][1] == board[1][2]);
            if (diag1 || diag2 || vert || hort)
            {
                cout << "Player " << board[1][1] << " Wins!\n";
                return true;
            }
        }
        if (board[2][2] != '-')
        {
            bool vert = (board[2][2] == board[0][2]) && (board[2][2] == board[1][2]);
            bool hort = (board[2][2] == board[2][1]) && (board[2][2] == board[2][0]);
            if (vert || hort)
            {
                cout << "Player " << board[2][2] << " Wins!\n";
                return true;
            }
        }
        // Check if board's filled
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (board[row][col] == '-')
                {
                    return false;
                };
            }
        }
        cout << "Draw!\n";
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

    vector<vector<char>> getBoard()
    {
        return board;
    }

private:
    // const int dim = 3;
    vector<vector<char>> board;
    bool xToMove;
};

class Minimax
{
public:
    Minimax();

private:
};

class MCTS
{
public:
    MCTS();

private:
};

int main()
{
    enum class Mode
    {
        pvp,
        pvai,
        aivai
    };

    enum class AI
    {
        mini,
        mcts
    };

    GameState gs;
    Mode mode;
    int choice;

    cout
        << "Choose which mode to play: \n"
        << "   0 - Player vs Player\n"
        << "   1 - Player vs AI\n"
        << "   2 - AI vs AI\n";
    cin >> choice;
    mode = (Mode)choice;
    while (!gs.isDone())
    {
        switch (mode)
        {
        case Mode::pvp:
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
            break;
        case Mode::pvai:
            cout << "Dum Dum\n";
            break;
        case Mode::aivai:
            cout << "He he\n";
            break;
        }
    }
    return 0;
}