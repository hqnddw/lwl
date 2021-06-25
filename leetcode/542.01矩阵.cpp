//
// Created by lwl on 2021/6/25.
//
#include <vector>
#include <climits>
#include <cmath>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        if (mat.empty())
            return vector<vector<int>>();
        queue<pair<int, int>> q;
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j] == 0)
                    q.push({i, j});
                else mat[i][j] = INT_MAX;
            }
        }
        vector<vector<int>> dir = {{-1, 0},
                                   {1,  0},
                                   {0,  -1},
                                   {0,  1}};
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int row = cur.first + dir[i][0];
                int col = cur.second + dir[i][1];
                if (row < 0 || row == mat.size() || col < 0 || col == mat[0].size()
                    || mat[row][col] <= mat[cur.first][cur.second] + 1)
                    continue;
                mat[row][col] = mat[cur.first][cur.second] + 1;
                q.push({row, col});
            }
        }
        return mat;
    }
};