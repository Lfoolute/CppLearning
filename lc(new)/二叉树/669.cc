//https://leetcode.cn/problems/trim-a-binary-search-tree/
//修建二叉搜索树




//这道题有想到不是简单的删除节点，还需要删除之后可能的二叉树重构
//然后在重构这里认为有很多种情况，试图一个个列出来，逐渐列出来太复杂了，就做不出来了
//题解的递归法还是那种感觉，自己调用自己，感觉自己确实是有找区间的功能，但就是想不明白这样一层调一层怎么最后就成功了
//递归的关键点还是在单层处理逻辑那一块，怎样有效利用下一层的返回值（也可能没有返回值），作为本层的结果

//然后迭代法确实是真的巧妙
//先把root主动移到范围内，很巧
//在左右分别把范围外的踢掉，范围内的收进去，最后返回root




//递归法
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
       if (root == nullptr) return nullptr;
       if (root->val < low) {//当前元素小于low，用本函数在右子树中寻找符合区间条件的头节点
        TreeNode* left = trimBST(root->right, low, high);
        return left;
       }
       if (root->val > high) {//当前元素大于high，用本函数在左子树中寻找符合区间条件的头节点
        TreeNode* right = trimBST(root->left, low, high);
        return right;
       }
       root->left = trimBST(root->left, low, high);//下一层处理完左子树的结果赋给root->left
       root->right = trimBST(root->right, low, high);//下一层处理完右子树的结果赋给root->right
       return root;
    }
};
//迭代法
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;

        while (root != nullptr && (root->val < low || root->val > high)) {
            if (root->val < low) root = root->right;
            else root = root->left;
        }
        TreeNode* cur = root;
        while (cur != nullptr) {//从根节点的左边往下去，一层一层把范围之外的去掉，范围之内的收进来
            while (cur->left && cur->left->val < low) {
                cur->left = cur->left->right;
            }
            cur = cur->left;//只有还有左节点，就下去一层看它的右子树，不漏掉范围内的
        }
        cur = root;
        while (cur != nullptr) {//从根节点的右边往下去，一层一层把范围之外的去掉，范围之内的收进来
            while (cur->right && cur->right->val >high) {
                cur->right = cur->right->left;
            }
            cur = cur->right;//只有还有右节点，就下去一层看它的左子树，不漏掉范围内的
        }
        return root;
    }
};