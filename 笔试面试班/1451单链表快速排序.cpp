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
    ListNode* quickSortList(ListNode* head) {
        if (!head || !head->next) return head;
        //都是虚拟节点，left->next才是真实的节点
        //为什么要加虚拟头节点？ 因为子链表可能为空，为了避免一些特殊情况的判断，加上虚拟头节点就一定不为空
        auto left = new ListNode(-1), mid = new ListNode(-1), right = new ListNode(-1);
        auto ltail = left, mtail = mid, rtail = right;
        int val = head->val;
        
        while (head) {
            if (head->val < val) ltail = ltail->next = head;
            else if (head->val == val) mtail = mtail->next = head;
            else rtail = rtail->next = head;
            head = head->next;
        }
        //清空一下队尾，如果不清空，结尾点在原链表中会连接其他点，出错
        ltail->next = mtail->next = rtail->next = NULL;
        
        //递归左区间和右区间
        left->next = quickSortList(left->next);
        right->next = quickSortList(right->next);

        //拼接三个链表
        get_tail(left)->next = mid->next; //这里找尾节点，直接传入left就可以，不要用left->next，因为不一定存在
        get_tail(left)->next = right->next; //mid不一定存在，所以还是从left开始，找尾节点
        
        auto p = left->next;
        delete left;
        delete mid;
        delete right;
        return p;
    }
    
    ListNode* get_tail(ListNode* head) {
        while (head->next) head = head->next;
        return head;
    }
};