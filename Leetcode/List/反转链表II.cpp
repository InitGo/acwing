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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // if (!head || !head->next || left == right) return head;
        auto dummy = new ListNode(-1); //建立虚拟头节点
        dummy->next = head; //指向head
        
        auto a = dummy; 
        for (int i = 0; i < left - 1; i ++ ) a = a->next; //a指向left前一个点
        
        auto pre = a->next, cur = pre->next; //pre指向left， cur指向left->next
        //从cur开始做反转，做right-left条边：
        //区间[left, right]共有right - left + 1个点， right - left条边
        for (int i = 0; i < right - left; i ++ ) {
            auto ne = cur->next; 
            cur->next = pre;
            pre = cur, cur = ne;
        }
        
        a->next->next = cur, a->next = pre;
        return dummy->next;
    }
};