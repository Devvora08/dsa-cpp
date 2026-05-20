#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char digit) {
    // 3 checks 
    // horizontal
    for(int j = 0; j < 9; j++) {
        if(board[row][j] == digit) {
            return false;
        }
    }
    // vertical
    for(int i = 0; i < 9; i++) {
        if(board[i][col] == digit) {
            return false;
        }
    }
    // grid box
    int startRow = (row/3) * 3;
    int startCol = (col/3) * 3;

    for(int i = startRow; i < startRow + 2; i++){
        for(int j = startCol; j < startCol + 2; j++) {
            if(board[i][j] == digit) {
                return false;
            }
        }
    }

    return true;
}

bool helper(vector<vector<char>>& board, int row, int col) {
    if(row == 9) return true;

    int nextRow = row, nextCol = col+1;
    if(nextCol == 9) {
        nextRow = row+1;
        nextCol = 0;
    }

    if(board[row][col] != '.') {
        return helper(board, nextRow, nextCol);
    }

    // place the digit
    for(char digit = '1'; digit <= '9'; digit++) {
        if(isSafe(board, row, col, digit)) {
            board[row][col] = digit;
            if(helper(board, nextRow, nextCol)) {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}

void solve(vector<vector<char>>& board) {
    cout << helper(board, 0 , 0) << endl;

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},

    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},

    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solve(board);

    return 0;
}