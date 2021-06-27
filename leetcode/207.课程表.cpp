//
// Created by lwl on 2021/6/27.
//
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> degree(numCourses, 0);
        for (auto v : prerequisites){
            graph[v[1]].push_back(v[0]);
            degree[v[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] == 0)
                q.push(i);
        }
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            numCourses--;
            for (int i : graph[cur]){
                degree[i]--;
                if (degree[i] == 0){
                    q.push(i);
                }
            }
        }
        return numCourses == 0;
    }
};