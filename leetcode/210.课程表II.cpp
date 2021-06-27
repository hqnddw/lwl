//
// Created by lwl on 2021/6/27.
//
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> res;
        queue<int> q;
        vector<int> degree(numCourses, 0);
        for (auto v : prerequisites) {
            graph[v[1]].push_back(v[0]);
            degree[v[0]]++;
        }
        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            numCourses--;
            for (int i : graph[cur])
                if (--degree[i] == 0)
                    q.push(i);
        }
        return numCourses == 0 ? res : vector<int>();
    }
};