//https://leetcode.cn/problems/n-queens/
//N皇后

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<int>> used(n, std::vector<int>(n, 0));
        backTracking(used, 0, n);
        return res;
    }
private:
    std::vector<std::string> loc;
    std::vector<std::vector<std::string>> res;
    void backTracking(std::vector<std::vector<int>>& used, int row, int n) {
        if (loc.size() == n) {
            res.push_back(loc);
            return;
        }
        std::string str;
        while(str.size() != n - 1) {
            str += '.';
        }
        for(int col = 0; col < n; ++col) {
            if (used[row][col] > 0) continue;
            str.insert(col, "Q");
            loc.push_back(str);
            setFlag(used, row, col, n, 1);
            backTracking(used, row + 1, n);
            str.erase(col, 1);
            loc.pop_back();
            setFlag(used, row, col, n, -1);
        }

    }
    void setFlag(std::vector<std::vector<int>>& used, int row, int col, int n, int flag) {
        int ud = row, lr = col;
        while (ud < n && lr > -1) {
            used[ud++][lr--] += flag;
        }
        lr = col, ud = row;
        while (ud < n && lr < n) {
            used[ud++][lr++] += flag;
        }
        while (row < n) {
            used[row++][col] += flag;
        }
    }
};