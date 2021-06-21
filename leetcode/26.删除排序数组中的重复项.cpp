#include <iostream>
#include <vector>

using namespace std;

// 双指针，一个指针指向非重复数组的末尾，一个指针用来遍历初始数组

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() < 2)
            return nums.size();
        int i = 0;
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};