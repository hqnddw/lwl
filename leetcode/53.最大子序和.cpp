//
// Created by lwl on 2021/6/23.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int cur = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (cur < 0) cur = nums[i];
            else cur = cur + nums[i];
            res = max(res, cur);
        }
        return res;
    }
};