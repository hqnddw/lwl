//
// Created by lwl on 2021/6/22.
//
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return x;
        long num = 0;
        while (x % 10 == 0) {
            x /= 10;
        }
        int flag = 1;
        if (num < 0) {
            flag = -1;
            num = -num;
        }
        long res = 0;

        while (x) {
            res = 10 * res + (x % 10);
            x /= 10;
        }
        return (res < INT_MIN || res > INT_MAX) ? 0 : int(res) * flag;
    }
};

int main() {
    Solution s;
    int x = -12345600;
    cout << s.reverse(x) << endl;
}