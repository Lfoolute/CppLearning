//https://leetcode.cn/problems/house-robber-iii/
//打家劫舍 III


//记忆化递推
class Solution {
    //利用map计算各节点的最大结果
    unordered_map<TreeNode*, int> sum;
public:
    int rob(TreeNode* root) {
        return robTree(root);
    }
private:
    int robTree(TreeNode* cur) {
        if (!cur) return 0;
        //如果map中已经存在该节点结果，直接返回
        if (sum.count(cur)) return sum[cur];
        //偷父节点
        int res1 = 0;
        //跳过父节点的左右子节点，去算各层的子节点
        if (cur->left) {
            res1 += robTree(cur->left->left) + robTree(cur->left->right);
        }
        if (cur->right) {
            res1 += robTree(cur->right->left) + robTree(cur->right->right);
        }
        res1 += cur->val;
        //不偷父节点
        int res2 = robTree(cur->left) + robTree(cur->right);
        sum[cur] = max(res1, res2);
        return sum[cur];
    }
};

//动规做法（使用vector），对每个节点的状态做记录
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
private:
    //采用长度为2的数组记录每个节点偷与不偷两种的最大金钱
    //采用后序遍历，这样不偷父节点的状态时，由左右子节点才知道此时父节点的最大金钱
    // 下标0：不偷，下标1：偷
    vector<int> robTree(TreeNode* cur) {
        if (cur == nullptr) return vector<int>{0, 0};
        vector<int> left = robTree(cur->left);//左
        vector<int> right = robTree(cur->right);//右
        //中
        //不偷
        int val1 = max(left[0], left[1]) + max(right[0], right[1]);
        //偷
        int val2 = cur->val + left[0] + right[0];
        return {val1, val2};
    }
};