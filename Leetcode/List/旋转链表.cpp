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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        int n = 0;
        for (auto p = head; p; p = p->next) n ++ ;
        
        k = k % n;
        if (!k) return head;
        
        auto p = head;
        for (int i = 0; i < n - k - 1; i ++ ) p = p->next; //p为要转换的前一个点
        
        auto tail = head; //tail为尾节点
        while (tail->next) tail = tail->next;
        
        tail->next = head; //尾节点指向旧的头节点
        head = p->next; //新的头节点为p的下一个
        p->next = NULL; //p设置为尾节点，指向空
      
        return head; //返回新的头节点
    }
};