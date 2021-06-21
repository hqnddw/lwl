//
// Created by lwl on 2021/6/21.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> v;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                int n = count(i) + count(j);
                if (n == turnedOn) {
                    string s;
                    s += to_string(i);
                    if (j < 10) {
                        s += ":0";
                    } else s += ":";
                    s += to_string(j);
                    v.push_back(s);
                }
            }
        }
        return v;
    }

    int count(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= (n - 1);
        }
        return res;
    }
};

int main() {
    Solution s;
    int n = 1;
    for (const string &str: s.readBinaryWatch(1)) {
        cout << str << " ";
    }
}