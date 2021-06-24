//
// Created by lwl on 2021/6/24.
//
#include <vector>
#include <cmath>

using namespace std;

class Solution1 {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<vector<int>> dp(triangle.size() + 1,
                               vector<int>(triangle.size() + 1, 0));
        for (int i = triangle.size() - 1; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};


class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<int> dp(triangle.size() + 1, 0);
        for (int i = triangle.size() - 1; i >= 0; --i)
            for (int j = 0; j < triangle[i].size(); ++j) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        return dp[0];
    }
};