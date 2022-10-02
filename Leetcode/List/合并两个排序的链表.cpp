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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1);  //建立虚拟节点dummy
        auto cur = dummy;  //cur记录新节点的尾节点，如果有新节点，就往cur后接

        while (l1 && l2) {
            if (l1->val < l2->val) {  //如果l1的值更小
                cur->next = l1;  //cur后面接l1
                cur = cur->next; //cur更新为尾节点
                l1 = l1->next;  //l1往后走
            }
            else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;          
            }
        }

        //还剩下一个不为空的链表，接在尾节点cur之后
        if (l1) cur->next = l1; 
        else cur->next = l2;
        return dummy->next;
    }
};