//
// Created by lwl on 2021/6/25.
//
#include <vector>
#include <queue>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution1 {
public:

    int getImportance(vector<Employee *> employees, int id) {
        int res = 0;
        for (auto it : employees) {
            if (it->id == id) {
                res += it->importance;
                if (!it->subordinates.empty()) {
                    for (int i : it->subordinates) {
                        res += getImportance(employees, i);
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        queue<int> q;
        int res = 0;
        q.push(id);
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (auto it : employees){
                if (it->id == cur){
                    res += it->importance;
                    for (int i : it->subordinates)
                        q.push(i);
                }
            }
        }
        return res;
    }
};