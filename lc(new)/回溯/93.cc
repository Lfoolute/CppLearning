//https://leetcode.cn/problems/restore-ip-addresses/
//复原IP地址


class Solution {
private:
    bool isIpaddr(const std::string& s, int index, int end) {
        if (index > end) return false;
        if (s[index] == '0' && index != end) return false;
        int num = 0;
		for (int j = index; j <= end; ++j) {
			if (s[j] > '9' || s[end] < '0')
                return false;
			num = num * 10 + (s[j] - '0');
			if (num > 255) return false;
		}
		return true;
    }
    std::vector<std::string> res;
    void backTracking(std::string& s, int index, int dots) {
        if (dots == 3) {
            if (isIpaddr(s, index, s.size() - 1)) {
                res.push_back(s);
            }
            return;
        }
        for (int i = index; i <= s.size(); ++i) {
            if (isIpaddr(s, index, i)) {
                s.insert(s.begin() + i + 1, '.');
                dots++;
                backTracking(s, i + 2, dots);
                dots--;
                s.erase(s.begin() + i + 1);

            }
            else break;
        }
    }
public:
    std::vector<std::string> restoreIpAddresses(std::string& s) {
        res.clear();
        backTracking(s, 0, 0);
        return res;
    }
};