//
// Created by lwl on 2021/6/24.
//
#include <vector>
#include <cmath>
#include <iostream>
#include <climits>
#include <set>

using namespace std;


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> set;
        for (int i : nums){
            set.insert(i);
            if (set.size() > 3){
                set.erase(set.begin());
            }
        }
        if (set.size() < 3) return *set.begin();
        else return *(--set.end());
    }
};