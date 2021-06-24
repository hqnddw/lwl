//
// Created by lwl on 2021/6/24.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> v;
        helper(res, v, n, 1, k);
        return res;
    }

    void helper(vector<vector<int>> &res, vector<int> &v,
                int n, int start, int k) {
        if (v.size() == k) {
            res.push_back(v);
            return;
        }
        for (int i = start; i <= n; ++i) {
            v.push_back(i);
            helper(res, v, n, i + 1, k);
            v.pop_back();
        }
    }
};