//https://leetcode.cn/problems/binary-tree-cameras/
//监控二叉树



class Solution {
public:
    int minCameraCover(TreeNode* root) {
        res = 0;
        // 情况4
        if (traversal(root) == 0) { // root 无覆盖
            res++;
        }
        return res;
    }
private:
    int res;
    int traversal(TreeNode* cur) {

        // 空节点，该节点有覆盖
        if (cur == NULL) return 2;

        int left = traversal(cur->left);    // 左
        int right = traversal(cur->right);  // 右

        // 情况1
        // 左右节点都有覆盖
        if (left == 2 && right == 2) return 0;

        // 情况2
        // left == 0 && right == 0 左右节点无覆盖
        // left == 1 && right == 0 左节点有摄像头，右节点无覆盖
        // left == 0 && right == 1 左节点有无覆盖，右节点摄像头
        // left == 0 && right == 2 左节点无覆盖，右节点覆盖
        // left == 2 && right == 0 左节点覆盖，右节点无覆盖
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }

        // 情况3
        // left == 1 && right == 2 左节点有摄像头，右节点有覆盖
        // left == 2 && right == 1 左节点有覆盖，右节点有摄像头
        // left == 1 && right == 1 左右节点都有摄像头
        // 其他情况前段代码均已覆盖
        if (left == 1 || right == 1) return 2;

        // 以上代码我没有使用else，主要是为了把各个分支条件展现出来，这样代码有助于读者理解
        // 这个 return -1 逻辑不会走到这里。
        return -1;
    }
};

//简化版本
class Solution {
//每个节点有三种状态
//无覆盖：val = 0
//摄像头：val = 1
//有覆盖：val = 2，叶子节点之下的空节点认为是有覆盖的
//根节点还有状态四：如果根节点属于没有被覆盖，则需要加一个摄像头
public:
    int minCameraCover(TreeNode* root) {
        res = 0;
        if (traversal(root) == 0) res++;
        return res; 
    }
private:
    int res;
    int traversal(TreeNode* cur) {
        if (cur == nullptr) return 2;
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        if (left == 2 && right == 2) return 0;
        else if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        else
            return 2;
    }
};
