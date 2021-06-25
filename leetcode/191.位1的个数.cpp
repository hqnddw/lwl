//
// Created by lwl on 2021/6/25.
//

#include <cstdint>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n){
            res++;
            n &= (n-1);
        }
        return res;
    }
};