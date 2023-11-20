//https://leetcode.cn/problems/queue-reconstruction-by-height/
//根据身高重建队列

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), 
            [](const auto& lhs, const auto& rhs) 
            {
                if (lhs[0] == rhs[0]) {
                    return lhs[1] < rhs[1];
                }
                return lhs[0] > rhs[0];
            });
        //这里用list更省空间
        list<vector<int>> res;
        for (int i = 0; i < people.size(); ++i) {
            int pos =people[i][1];
            list<vector<int>>::iterator iter = res.begin();
            while (pos--) {
                iter++;
            }
            res.insert(iter, people[i]);
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};