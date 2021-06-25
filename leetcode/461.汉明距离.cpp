//
// Created by lwl on 2021/6/25.
//

class Solution1 {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while (x || y) {
            if ((x % 2) != (y % 2))
                res++;
            x = x >> 1;
            y = y >> 1;
        }
        return res;
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int res = 0;
        while (z) {
            res += (z & 1);
            z >>= 1;
        }
        return res;
    }
};