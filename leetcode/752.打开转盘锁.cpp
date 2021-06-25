//
// Created by lwl on 2021/6/25.
//
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> visited;
        for (const auto &s : deadends)
            visited.insert(s);
        if (visited.find(target) != visited.end()
        || visited.find("0000") != visited.end())
            return -1;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur.first == target)
                return cur.second;
            string tmp;
            for (int j = 0; j < 4; ++j) {
                for (int k = -1; k <= 1; k += 2) {
                    tmp = cur.first;
                    if (k == -1 && tmp[j] == '0')
                        tmp[j] = '9';
                    else if (k == 1 && tmp[j] == '9')
                        tmp[j] = '0';
                    else tmp[j] += k;
                    if (visited.find(tmp) != visited.end())
                        continue;
                    else {
                        q.push({tmp, cur.second + 1});
                        visited.insert(tmp);
                    }
                }
            }
        }
        return -1;
    }
};
