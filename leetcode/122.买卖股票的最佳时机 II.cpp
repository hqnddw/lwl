//
// Created by lwl on 2021/6/21.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0)
                sum += prices[i] - prices[i - 1];
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> v = {7,1,5,3,6,4};
    cout<<s.maxProfit(v)<<endl;
}