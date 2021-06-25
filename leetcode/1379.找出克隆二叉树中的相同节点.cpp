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

//值不相同时
class Solution1 {
public:
    TreeNode *res = nullptr;

    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        helper(cloned, target);
        return res;
    }

    void helper(TreeNode *cloned, TreeNode *target) {
        if (!cloned) return;
        helper(cloned->left, target);
        if (cloned->val == target->val)
            res = cloned;
        helper(cloned->right, target);
    }
};

//值相同时
class Solution {
public:
    TreeNode *res = nullptr;

    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(original);
        q2.push(cloned);
        while (!q1.empty()){
            TreeNode* cur1 = q1.front();
            TreeNode* cur2 = q2.front();
            q1.pop();
            q2.pop();
            if (cur1 == target)
                return cur2;
            if (cur1->left){
                q1.push(cur1->left);
                q2.push(cur2->left);
            }
            if (cur1->right){
                q1.push(cur1->right);
                q2.push(cur2->right);
            }
        }
        return nullptr;
    }
};