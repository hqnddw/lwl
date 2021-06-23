//
// Created by lwl on 2021/6/23.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 1)
            return 0;
        vector<int> v;
        for (int i = 1; i < prices.size(); ++i) {
            v.push_back(prices[i] - prices[i - 1]);
        }
        int res = v[0];
        int cur = v[0];
        for (int i = 1; i < v.size(); ++i) {
            if (cur < 0) cur = v[i];
            else cur += v[i];
            res = max(max(cur, res), 0);
        }
        return res;
    }
};