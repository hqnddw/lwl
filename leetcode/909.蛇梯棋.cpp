//
// Created by lwl on 2021/6/27.
//
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int row = board.size();
        int n = row * row;
        vector<int> v(n);
        vector<bool> visited(n);
        int flag = 0;
        int cnt = 0;
        for (int i = row - 1; i >= 0; --i) {
            if (flag % 2 == 0) {
                for (int j = 0; j < row; ++j) {
                    v[cnt] = board[i][j];
                    cnt++;
                }
            } else {
                for (int j = row - 1; j >= 0; --j) {
                    v[cnt] = board[i][j];
                    cnt++;
                }
            }
            flag++;
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int cur = q.front();
                q.pop();
                if (cur == n - 1) return res;
                for (int i = cur + 1; i <= min(n - 1, cur + 6); ++i) {
                    int next = v[i] == -1 ? i : v[i] - 1;
                    if (!visited[next]){
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};

