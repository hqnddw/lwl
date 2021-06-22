//
// Created by lwl on 2021/6/22.
//
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;


// set去重
class Solution1 {
public:
    vector<string> permutation(string s) {
        unordered_set<string> res;
        string str;
        vector<bool> visited(s.size(), false);
        helper(s, res, str, visited);
        vector<string> v(res.begin(), res.end());
        return v;
    }

    void helper(string &s, unordered_set<string> &res, string str, vector<bool> &visited) {
        if (str.size() == s.size()) {
            res.insert(str);
            return;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            helper(s, res, str + s[i], visited);
            visited[i] = false;
        }
    }
};

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        if (s.empty()) return res;
        sort(s.begin(), s.end());
        string str;
        vector<bool> visited(s.size(), false);
        helper(s, res, str, visited);
        return res;
    }

    void helper(string &s, vector<string> &res, string str, vector<bool> &visited) {
        if (str.size() == s.size()) {
            res.push_back(str);
            return;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (visited[i] || (i > 0 && !visited[i - 1] && s[i] == s[i - 1]))
                continue;
            visited[i] = true;
            helper(s, res, str + s[i], visited);
            visited[i] = false;
        }
    }
};

int main() {
    vector<string> res;
    string str("aac");
    Solution s;
    res = s.permutation(str);
    for (const auto &v: res) {
        cout << v << endl;
    }
}