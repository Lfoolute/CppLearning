//https://leetcode.cn/problems/gas-station/
//加油站

//为什么要将新起点设为 i+1 
//  因为 i 到 i+1 站耗油太多，在前i个站点中，往前一个就少一点油，所以从前i个站任何一个站出发都过不了这道关

//为什么
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int curSum = 0;
        int sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            curSum += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        return sum < 0 ? -1 : start;
    }
};
