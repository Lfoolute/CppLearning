//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ////回溯(后序遍历)
        
        ////终止条件
        if (root == p || root == q || root == nullptr) return root;
        ////单层递归逻辑
        //左
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        //右
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        ////中间节点处理逻辑
        //中
        if (left != nullptr && right != nullptr) return root;
        // if (left == nullptr && right != nullptr) return right;
        // else if (left != nullptr && right ==nullptr) return left;
        // else return nullptr;
        if (left == nullptr) return right;
        return left;
    }
};