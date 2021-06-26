//
// Created by lwl on 2021/6/26.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b,
                             ListNode *list2) {
        ListNode *res = new ListNode(-1);
        res->next = list1;
        ListNode *cur = res;
        int tmp = a;
        while (a) {
            cur = cur->next;
            a--;
        }
        ListNode *tail = cur->next;
        cur->next = list2;
        ListNode *l2 = list2;
        while (l2->next) {
            l2 = l2->next;
        }
        int n = b - tmp;
        while (n) {
            tail = tail->next;
            n--;
        }
        l2->next = tail->next;
        tail->next = nullptr;
        return res->next;
    }
};