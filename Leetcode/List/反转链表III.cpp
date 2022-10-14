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
//K 个一组翻转链表
//k个一组反转链表，如果最后剩下不足k个，剩下的原样返回
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        for (auto p = head; p; p = p->next) len ++ ;
        if (len < k) return head;

        auto dummy = new ListNode(-1);
        dummy->next = head;

        //这次的起点是上一次翻转的终点  精髓是这个！！！有了这个就有了一切。
        auto before_tail = dummy;
        for (int i = 0; i < len / k; i ++ ) {
            auto prev = before_tail->next, cur = prev->next;
            for (int j = 0; j < k - 1; j ++ ) { //反转k个点，k-1条边
                auto ne = cur->next;
                cur->next = prev;
                prev = cur, cur = ne;
            }
            auto new_before_tail = before_tail->next; //先存下来下一次操作的起点节点new_before_tail
            before_tail->next->next = cur, before_tail->next = prev;
            
            before_tail = new_before_tail;
        }

        return dummy->next;
    }
};
