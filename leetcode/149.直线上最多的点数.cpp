//
// Created by lwl on 2021/6/24.
//
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <unordered_set>
#include <limits>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double, int> hashmap;
        int n = points.size();
        int max_pts = 1;
        //choosing the starting element
        for(int i = 0; i<n; i++) {
            hashmap.clear();
            //choose the second point
            for(int j = i+1; j<n; j++) {
                //calculate the slope
                double slope = 0;
                if(points[j][0] == points[i][0]) {
                    //edge case, when slope is infinity
                    slope = std::numeric_limits<double>::infinity();
                }
                else {
                    //normal slope calculation
                    slope = (double) (points[j][1] - points[i][1]) / (double) (points[j][0] - points[i][0]);
                }
                //increment the counts for this slope, if already seen, otherwise create a new entry
                if(hashmap.find(slope) == hashmap.end()) {
                    hashmap[slope] = 1;
                }
                else {
                    hashmap[slope]++;
                }
            }
            //calculate the maxima
            for(auto h: hashmap) {
                //adding 1 to accomodate the starting point as well
                max_pts = max(max_pts, 1+ h.second);
            }
        }
        return max_pts;
    }
};

int main() {
    vector<vector<int>> points{{1, 1},
                               {3, 2},
                               {5, 3},
                               {4, 1},
                               {2, 3},
                               {1, 4}};
    Solution s;
    cout << s.maxPoints(points) << endl;
}