//
// Created by lwl on 2021/6/26.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode *oddEvenList(ListNode *head) {
        ListNode *odd = new ListNode(-1);
        ListNode *res = odd;
        ListNode *even = new ListNode(-1);
        ListNode* l2 = even;
        int cnt = 1;
        while (head) {
            if (cnt % 2 == 1) {
                odd->next = head;
                odd = odd->next;
            } else {
                even->next = head;
                even = even->next;
            }
            head = head->next;
            cnt++;
        }
        even->next = nullptr;
        odd->next = l2->next;
        return res->next;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *l2 = even;
        ListNode *cur = even;
        while (cur && cur->next){
            ListNode *next = cur->next;
            odd->next = next;
            odd = odd->next;
            even->next = next->next;
            even = even->next;
            cur = next->next;
        }
        odd->next = l2;
        return head;
    }
};