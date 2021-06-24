//
// Created by lwl on 2021/6/24.
//
#include <stack>

using namespace std;

class MinStack {
public:
    stack<pair<int, int>> s;

    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        if (s.empty()) s.push({val, val});
        else {
            if (s.top().second < val)
                s.push({val, s.top().second});
            else s.push({val, val});
        }
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
};
