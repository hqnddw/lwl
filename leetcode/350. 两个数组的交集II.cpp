//
// Created by lwl on 2021/6/22.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> res;
        for(int i : nums1)
            map[i]++;
        for(int i : nums2){
            if (map[i] > 0){
                res.push_back(i);
                map[i]--;
            }
        }
        return res;
    }
};