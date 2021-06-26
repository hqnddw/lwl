//
// Created by lwl on 2021/6/26.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};


class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
        }
        for (++i; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};