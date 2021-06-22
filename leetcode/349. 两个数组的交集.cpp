//
// Created by lwl on 2021/6/22.
//
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> set;
        for (int i : nums1){
            set.insert(i);
        }
        unordered_set<int> set1(nums2.begin(), nums2.end());
        for(int i : set1){
            if (set.find(i) != set.end())
                res.push_back(i);
        }
        return res;
    }
};