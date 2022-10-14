/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//细节：midi就是反转链表的prev
class Solution {
public:
    void reorderList(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) n ++ ;
        if (n <= 2) return;

        int half = n / 2;
        auto mid = head;
        for (int i = 0; i < half; i ++ ) mid = mid->next;

        auto prev = mid, cur = prev->next;
        mid->next = nullptr;
        for (int i = 0; i < n - half - 1; i ++ ) {
            auto ne = cur->next;
            cur->next = prev;
            prev = cur, cur = ne;
        }
        // while (cur)

        auto p = head, q = prev;
        //while (p != q && p->next != q) {
        for (int i = 0; i < (n - 1) / 2; i ++ ) {
            auto ne = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next, q = ne;
        }
    }
};