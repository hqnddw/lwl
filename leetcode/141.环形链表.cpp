//
// Created by lwl on 2021/6/26.
//
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        unordered_set<ListNode*> set;
        while (head){
            set.insert(head);
            head = head->next;
            if (set.find(head) != set.end())
                return true;
        }
        return false;
    }
};