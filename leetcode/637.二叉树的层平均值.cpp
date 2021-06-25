//
// Created by lwl on 2021/6/25.
//
#include <vector>
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
    vector<double> averageOfLevels(TreeNode* root) {
       queue<TreeNode*> q;
       vector<double> res;
        if (!root) return res;
        q.push(root);
        while (!q.empty()){
            int sum = 0;
            size_t n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                sum += cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            res.push_back((double)sum/(double )n);
        }
        return res;
    }
};
