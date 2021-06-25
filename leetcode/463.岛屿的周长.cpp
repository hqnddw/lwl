//
// Created by lwl on 2021/6/25.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1){
                    if (i == 0 || grid[i - 1][j] == 0)
                        res++;
                    if (i == grid.size() - 1 || grid[i + 1][j] == 0)
                        res++;
                    if (j == 0 || grid[i][j - 1] == 0)
                        res++;
                    if (j == grid[i].size() - 1 || grid[i][j + 1] == 0)
                        res++;
                }
            }
        }
        return res;
    }
};

int main(){
    cout<<sizeof(void*)<<endl;
}