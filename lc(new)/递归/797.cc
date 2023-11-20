//https://leetcode.cn/problems/all-paths-from-source-to-target/
//所有可能路径

class Solution {
public:
    vector<int> path{0};
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return res;
    }
private:
    void dfs(vector<vector<int>>& graph, int index) {
        if (index == graph.size() - 1) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < graph[index].size(); ++i) {
            path.push_back(graph[index][i]);
            dfs(graph, graph[index][i]);
            path.pop_back();
        }
    }
};