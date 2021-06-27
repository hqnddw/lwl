//
// Created by lwl on 2021/6/27.
//
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            if (isalpha(s[i]) && isalpha(s[j])) {
                if (tolower(s[i]) != tolower(s[j]))
                    return false;
            } else if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};