//
// Created by lwl on 2021/6/26.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

/*
 * -1->1->2->3>->2->1
 * -1->1->2->2->1
 * */
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *l1 = head;
        dummy->next = head;
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l2 = slow->next;
        slow->next = nullptr;
        ListNode *pre = nullptr;
        ListNode *cur = l2;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        while (l1 && pre) {
            if (l1->val != pre->val)
                return false;
            l1 = l1->next;
            pre = pre->next;
        }
        return true;
    }
};
