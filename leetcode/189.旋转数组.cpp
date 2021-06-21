//
// Created by lwl on 2021/6/21.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end() - k);
        display(nums);
        reverse(nums.end() - k, nums.end());
        display(nums);
        reverse(nums.begin(), nums.end());
        display(nums);
    }

    void display(vector<int> &v) {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
};

int main() {
    Solution s;
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    s.rotate(v, k);
}