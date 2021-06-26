//
// Created by lwl on 2021/6/26.
//
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int n = 0;

    vector<int> nextLargerNodes(ListNode *head) {
        ListNode *l1 = reverse_list(head);
        vector<int> res(n);
        stack<int> s;
        while (l1) {
            if (s.empty()) {
                res[n - 1] = 0;
            } else {
                while (!s.empty() && l1->val >= s.top()) {
                    s.pop();
                }
                if (s.empty()) res[n - 1] = 0;
                else res[n - 1] = s.top();
            }
            n--;
            s.push(l1->val);
            l1 = l1->next;
        }
        return res;
    }

    ListNode *reverse_list(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            n++;
        }
        return pre;
    }
};
