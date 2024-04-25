#include <iostream>
using namespace std;

class TicTacToe
{
private:
    char **grid;
    char player1 = 'X';
    char player2 = 'O';

public:
    void dynamicMemory()
    {
        grid = nullptr;
        grid = new char *[3];
        for (int i = 0; i < 3; i++)
        {
            grid[i] = new char[3];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                grid[i][j] = ' ';
            }
        }
    }
    bool isWin(char player)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
                return true;
            if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)
                return true;
        }
        if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
            return true;
        if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
            return true;
        return false;
    }
    void switchPlayers()
    {
        if (player1 == 'X' && player2 == 'O')
        {
            player1 = 'O';
            player2 = 'X';
            cout << "Now Player1 is 'O' and Player2 is 'X'" << endl;
        }
        else
        {
            player1 = 'X';
            player2 = 'O';
            cout << "Now Player1 is 'X' and Player2 is 'O'" << endl;
        }
    }
    void assignValue(int index, int row, int col)
    {
        if (row >= 0 || row < 3 && col >= 0 || col < 3)
            if (index % 2 == 0)
            {
                grid[row][col] = player1;
            }
            else
            {
                grid[row][col] = player2;
            }
        else
            cout << "Wrong indexing" << endl;
    }
    void display()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << i << j << " __ " << grid[i][j] << " __ | ";
            }
            cout << endl;
        }
    }
    void Game()
    {
        dynamicMemory();
        int row;
        int col;
        cout << "Player1 has the First Turn" << endl;
        display();

        for (int i = 0; i < 9; i++)
        {
            if (!isWin(player1) && !isWin(player2))
            {
                cout << "Enter the row and column" << endl;
                cin >> row >> col;
                assignValue(i, row, col);
                display();
            }

            else if (isWin(player1) == 1)
            {
                cout << "Player1 Win" << endl;
                grid = nullptr;
                break;
            }
            else if (isWin(player2) == 1)
            {
                cout << "Player2 Win" << endl;
                grid = nullptr;
                break;
            }
            else
            {
                cout << "Game is Draw" << endl;
                break;
            }
        }
    }
    ~TicTacToe()
    {
        for (int i = 0; i < 3; i++)
        {
            delete[] grid[i];
        }
        delete[] grid;
        cout << "DESTRUCTOR IS CALLED" << endl;
    }
};
int main()
{
    TicTacToe A;
    char choice;
    int input = 0;
    do
    {
        cout << "--- TIC TAC TOE GAME ---" << endl;
        cout << "By Default Player1 is 'X' and Player2 is 'O' " << endl;
        cout << "Press 1 : To alternate Players" << endl;
        cout << "Press 2 : To Display Board" << endl;
        cout << "Press 3 : For Start New Game" << endl;
        cout << "Press 4 : To Exit Game" << endl;
        cin >> input;
        if (input == 1)
        {
            A.switchPlayers();
        }
        else if (input == 2)
        {
            A.display();
        }
        else if (input == 3)
        {
            A.Game();
        }
        else if (input == 4)
        {
            break;
        }
        else
        {
            cout << "Wrong Input" << endl;
        }

        cout << "Do You Want to Continue if Yes press Y/y & if NO press N/n" << endl;
        cin >> choice;
    } while (choice != 'N' && choice != 'n');

    return 0;
}
