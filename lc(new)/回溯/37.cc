//https://leetcode.cn/problems/sudoku-solver/
//解数独


class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        backTracking(board);
    }
private:
    //这里回溯有返回值
    bool backTracking(std::vector<std::vector<char>>& board) {
        //这里有个二维递归
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') continue;
                for (char ch = '1'; ch <= '9'; ++ch) {
                    if (!isValid(i, j, ch, board)) continue;
                    board[i][j] = ch;
                    if (backTracking(board)) return true;//遇到合适的就返回，上一级继续向下一列去试
                    board[i][j] = '.';
                }
                return false;//9个数都试过都不行，返回false，回溯到上一级
            }
        }
        return true;
    }
    bool isValid(int row, int col, char ch, std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            if (ch == board[i][col]) return false;
        }
        for (int i = 0; i < 9; ++i) {
            if (ch == board[row][i]) return false;
        }
        int rowstart = (row / 3) * 3;
        int colstart = (col / 3) * 3;
        for (int i = rowstart; i < rowstart + 3; ++i) {
            for (int j = colstart; j < colstart + 3; ++j) {
                if (ch == board[i][j]) return false;
            }
        }
        return true;
    }
};