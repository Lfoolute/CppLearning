//https://leetcode.cn/problems/number-of-islands/
//岛屿数量

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<bool>> traveled(m, vector<bool>(n ,false));
        for (int i = 0; i < m; ++i) {
            for (int j =0; j < n; ++j) {
                if (grid[i][j] == '1' && !traveled[i][j]) {
                    checkPoint(grid, traveled, i, j);
                    res++;
                }
            }
        }
        return res;
    }
private:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void checkPoint(vector<vector<char>>& grid, vector<vector<bool>>& traveled, int x, int y) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
            if (!traveled[nx][ny] && grid[nx][ny] == '1') {
                traveled[nx][ny] = true;
                checkPoint(grid, traveled, nx, ny);
            }
        }
    }
};


//空间优化版
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j =0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    checkPoint(grid, i, j);
                    res++;
                }
            }
        }
        return res;

    }
private:
    void checkPoint(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1') return;
        grid[i][j]++;
        checkPoint(grid, i + 1, j);
        checkPoint(grid, i - 1, j);
        checkPoint(grid, i, j + 1);
        checkPoint(grid, i, j - 1);
    }
};