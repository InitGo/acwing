/*
插入排序算法步骤：

1. 从前往后扫描原链表，每次将一个原链表的节点插入结果链表；
2. 要插入到结果链表的合适位置，使得插入后的链表有序；
3. 扫描完原链表后，算法结束；
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        //if (!head || !head->next) return head;
        auto dummy = new ListNode(-1); //头节点可能变化,使用虚拟头节点
        //这里没有dummy->next = head,因为是维护一个全新的链表，作为插入对象
        while (head) {
            auto next = head->next; //head是要处理的点,所以先存下它的next
            auto cur = dummy;
            //用cur->next去比较,避免维护先驱节点
            while (cur->next && cur->next->val <= head->val) cur = cur->next;
            //定位好cur以后, head就插入到cur之后
            head->next = cur->next;
            cur->next = head;

            head = next;
        }

        auto p = dummy->next;
        delete dummy;
        return p;
    }
};