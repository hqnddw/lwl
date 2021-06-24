//
// Created by lwl on 2021/6/24.
//
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> res;
        unordered_map<int, int> map;
        for (int i : nums) {
            map[i]++;
            if (map[i] >= 2)
                res.push_back(i);
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1])
                res.push_back(nums[i]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
                res.push_back(abs(nums[i]));
            nums[index] = -nums[index];
        }
        return res;
    }
};