//
// Created by lwl on 2021/6/25.
//
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        TreeNode *root = nullptr;
        if (!root1 && !root2) return root;
        else if (!root2) {
            return root1;
        } else if (!root1) {
            return root2;
        } else {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
            return root1;
        }
    }
};