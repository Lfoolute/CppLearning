//https://leetcode.cn/problems/course-schedule-ii/
//课程表

//拓扑排序
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> map;//统计每个节点的邻接点
        //统计每个节点的入度，但这里比较诡异，和官方数组的意思相反
        //这里根据依赖关系建图，[1,0]表示要完成1，依赖于先完成0，所以是1->0
        //如果按照官方的顺序，用stack最后还需要反转一次，这里从栈中pop依次出来到数组就是正确的顺序
        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            map[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        stack<int> s;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) s.push(i);
        }

        stack<int> order;
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            order.push(cur);
            for (auto& pre : map[cur]) {
                indegree[pre]--;
                if (indegree[pre] == 0) s.push(pre);
            }
        }

        vector<int> res;
        if (order.size() < numCourses) return res;
        while (!order.empty()) {
            res.push_back(order.top());
            order.pop();
        }
        return res;
    }
};