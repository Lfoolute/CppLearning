//https://leetcode.cn/problems/partition-labels/
//划分字母区间

/////有效说明了当数据不是很多的时候，数组相比哈希表更有效率

//用数组统计
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27]={0};
        //统计字符出现的最后位置
        for (int i = 0; i < s.size(); ++i) {
            hash[s[i] - 'a'] = i;
        }
        vector<int> res;
        int ls = 0, rs = 0;
        for (int i = 0; i < s.size(); ++i) {
            //找到字符出现的最远边界
            //遍历到当前位置为止，所包含的所有字母的最大边界
            rs = max(rs, hash[s[i] - 'a']);
            if (i == rs) {
                res.push_back(rs - ls + 1);
                ls = i + 1;
            }
        }
        return res;
    }
};

//用unordered_map统计
class Solution {
public:
    vector<int> partitionLabels(const string& s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); ++i) {
           map[s[i]] = i;
        }
        vector<int> res;
        int index = 0;
        int maxRange = 0;
        for (int i = 0;  i < s.size(); ++i) {
            //遍历到当前位置为止，所包含的所有字母的最大边界
            maxRange = max(maxRange, map[s[i]]);
            
            if (i == maxRange) {
                res.push_back(maxRange - index + 1);
                index = i + 1;
            }
        }
        return res;
    }
};