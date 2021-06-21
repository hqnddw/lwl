//
// Created by lwl on 2021/6/21.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


//哈希表
class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (++map[nums[i]] == 2)
                return true;
        }
        return false;
    }
};

//排序
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};