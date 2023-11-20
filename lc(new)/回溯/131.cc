//https://leetcode.cn/problems/palindrome-partitioning/
//分割回文串


class Solution {
private:
    bool palindromeCheck(const std::string& s, int lhs, int rhs) {
        if (lhs == rhs) return true;
        while (lhs < rhs) {
            if (s[lhs] == s[rhs]) {
                lhs++;
                rhs--;
            }
            else return false;
        }
        return true;
    }
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> strPath;
    void backTracking(const std::string& s, int index) {
        if (index == s.size()) {
            res.push_back(strPath);
            return;
        }
        for (int i =index; i < s.size(); ++i) {
            if (palindromeCheck(s, index, i) == false) continue;
            strPath.push_back(s.substr(index, i - index + 1));
            backTracking(s, i + 1);
            strPath.pop_back();
        }
    }
public:
    std::vector<std::vector<std::string>> partition(const std::string& s) {
        res.clear();
        strPath.clear();
        backTracking(s, 0);
        return res;
    }
};

/////回文串判断优化的版本
class Solution {
private:
    std::vector<std::vector<bool>> isPalindrome;
    //回文判断
    void computePalindrome(const std::string& s) {
        // isPalindrome[i][j] 代表 s[i:j](双边包括)是否是回文字串
        isPalindrome.resize(s.size(), std::vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (j == i) isPalindrome[i][j] = true;
                else if (j - i == 1) isPalindrome[i][j] = (s[i] == s[j]);
                else isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
            }
        }
    }
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> strPath;
    void backTracking(const std::string& s, int index) {
        if (index >= s.size()) {
            res.push_back(strPath);
            return;
        }
        for (int i =index; i < s.size(); ++i) {
            if (!isPalindrome[index][i]) continue;
            strPath.push_back(s.substr(index, i - index + 1));
            backTracking(s, i + 1);
            strPath.pop_back();
        }
    }
public:
    std::vector<std::vector<std::string>> partition(const std::string& s) {
        res.clear();
        strPath.clear();
        computePalindrome(s);
        backTracking(s, 0);
        return res;
    }
};