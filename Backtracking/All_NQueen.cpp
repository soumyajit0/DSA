#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 1)
            {
                cout << "Q ";
            }
            else
            {
                cout << "_ ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>> board, int row, int col)
{
    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    for (int i = col; i >= 0; i--)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < board[0].size(); i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

int nQueen(int row, vector<vector<int>> board)
{
    if (row == board.size())
    {
        display(board);
        return 1;
    }
    int count = 0;
    for (int col = 0; col < board[0].size(); col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
            count += nQueen(row + 1, board);
            board[row][col] = 0;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (!nQueen(0, board))
    {
        cout << "No possible solution exists\n";
    }
}