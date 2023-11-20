//https://leetcode.cn/problems/delete-node-in-a-bst/
//删除二叉树中的节点

//递归法
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;//情况一：未找到删除的节点
        if (root->val == key) {
            //情况二：左右节点均为空，直接删除，并返回空节点
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            //情况三：左节点空，返回右节点
            else if (root->left == nullptr) {
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
            //情况四：右节点空，返回左节点
            else if (root->right == nullptr) {
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
            //情况五：左右节点均不为空，以下操作
            else {
                TreeNode* cur = root->right;
                while (cur->left) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};


//迭代法
class Solution {
private:
    TreeNode* deleteOneNode(TreeNode* cur) {
        if (cur == nullptr) return cur;
        if (cur->right == nullptr) return cur->left;
        TreeNode* tmp = cur->right;
        while (tmp->left) {
            tmp = tmp->left;
        }
        tmp->left = cur->left;
        return cur->right;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* cur = root;
        TreeNode* parent = nullptr;
        while (cur) {
            if (key == cur->val) break;
            parent = cur;
            if (key > cur->val) cur = cur->right;
            else cur = cur->left;
        }
        if (parent == nullptr) return deleteOneNode(cur);

        if (parent->left && parent->left->val == key) {
            parent->left = deleteOneNode(cur);
        }
        if (parent->right && parent->right->val == key) {
            parent->right = deleteOneNode(cur);
        }
        return root;
    }
};
