//
// Created by lwl on 2021/6/23.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

//层次遍历
class Solution1 {
public:
    int maxDepth(Node *root) {
        int res = 0;
        if (!root) return res;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            res++;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                Node *tmp = q.front();
                q.pop();
                for (auto j : tmp->children) {
                    if (j) q.push(j);
                }
            }
        }
        return res;
    }
};

//递归版
class Solution {
public:
    int maxDepth(Node *root) {
        if (!root) return 0;
        int res = 0;
        for (auto it : root->children) {
            res = max(res, maxDepth(it));
        }
        return res + 1;
    }
};
