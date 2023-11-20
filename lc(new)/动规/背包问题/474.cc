//https://leetcode.cn/problems/ones-and-zeroes/
//一和零

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto& s : strs) {
            int zn = 0, on = 0;
            for (auto& c : s) {
                if (c == '0') zn++;
                else on++;
            }
            for (int i = m; i > zn; --i) {
                for (int j = n; j > on; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zn][j - on] + 1);
                }
            }
        }
        return dp[m][n];
    }
};