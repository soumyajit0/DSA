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
                cout << "K ";
            }
            else
            {
                cout << "_ ";
            }
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>> board, int row, int col)
{
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j -= 2)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i -= 2, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < board[0].size(); i -= 2, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < board[0].size(); i--, j += 2)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

int nKnight(int row, vector<vector<int>> board)
{
    if (row == board.size())
    {
        display(board);
        cout << endl;
        return 1;
    }
    int count = 0;
    for (int col = 0; col < board[0].size(); col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
            count += nKnight(row + 1, board);
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
    if (!nKnight(0, board))
    {
        cout << "No possible solution exists\n";
    }
}