//https://leetcode.cn/problems/word-break/
//单词拆分

class Solution {
public:
    bool wordBreak(const string& s, const vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        //先背包，后物品
        //但本题还有特殊性，因为是要求子串，最好是遍历背包放在外循环，将遍历物品放在内循环。
        //如果要是外层for循环遍历物品，内层for遍历背包，就需要把所有的子串都预先放在一个容器里。
        //（如果不理解的话，可以自己尝试这么写一写就理解了）
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string str = s.substr(j, i - j);
                if (set.find(str) != set.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
//迭代
class Solution {
public:
    bool wordBreak(const string& s, const vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            //这里倒序
            for (int j = i; j >= 0; --j) {
                if (set.find(s.substr(j, i - j)) != set.end() && dp[j]) {
                    dp[i] = true;
                    break;//这里找到就退出这层循环
                }
            }
        }
        return dp[s.size()];
    }
};
//再迭代
class Solution {
public:
    bool wordBreak(const string& s, const vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        int maxLengh = 0;
        for (auto& str : wordDict) {
            maxLengh = max(maxLengh, (int)str.size());
        }
        //主要靠maxLength进行剪枝
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i; j >= 0 && i - j <= maxLengh; --j) {
                if (set.find(s.substr(j, i - j)) != set.end() && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
