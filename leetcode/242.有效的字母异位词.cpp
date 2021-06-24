//
// Created by lwl on 2021/6/24.
//
#include <string>
#include <algorithm>

using namespace std;

//排序
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

//统计每个字符出现的次数
class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        for (auto c : s)
            arr[c - 'a']++;
        for (auto c : t) {
            arr[c - 'a']--;
        }
        for (int i = 0; i < 25; ++i) {
            if (arr[i] != 0)
                return false;
        }
        return true;
    }
};