/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* findKthToTail(ListNode* head, int k) {
        int n = 0;
        for (auto p = head; p; p = p->next) n ++ ; //先求出链表的长度
        if (n < k) return nullptr;  //如果k越界，返回null
        auto p = head; //找到倒数第k个节点，正数第n-k+1个节点
        for (int i = 0; i < n - k; i ++ ) p = p->next; //第二个节点，往前走一步，第n-k+1个，往前走n-k步
        return p;
    }
};