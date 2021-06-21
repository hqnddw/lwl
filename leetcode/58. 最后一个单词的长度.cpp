//
// Created by lwl on 2021/6/21.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        if (s.empty()) return res;
        int n = s.size() - 1;
        while (n >= 0) {
            if (s[n] == ' ')
                n--;
            else break;
        }
        s = s.substr(0, n + 1);
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                break;
            }
            res++;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLastWord("a ") << endl;
}