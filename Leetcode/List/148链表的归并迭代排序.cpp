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
    ListNode* sortList(ListNode* head) {
        //计算链表长度n
        int n = 0;
        for (auto p = head; p; p = p->next) n ++ ;

        //链表的头节点可能会变, 建立虚拟头系节点
        auto dummy = new ListNode(-1);
        dummy->next = head;

        //i表示迭代层数,第i层,所有长度为i的小区间已经排好序
        //需要把成对的长度为i的小区间合并成长度为2i的区间, 这层做完以后下一层的i为2i了
        //当i=n,表示长度为n的区间已经排好序,所以i的取值范围为[1, n), i*= 2
        for (int i = 1; i < n; i *= 2) {
            //现在横向处理这一层的所有子区间
            auto cur = dummy; //cur为dummy 的尾节点
            //每次处理两个区间,左区间的起点为第j个点, 右区间的起点为第j+i个点
            //每次处理完两个区间后, j += i * 2
            for (int j = 1; j + i <= n; j += i * 2) {
                //找到左区间和右区间的起点p, q
                auto p = cur->next, q = p;
                for (int k = 0; k < i; k ++ ) q = q->next; //p往后跳i次就是q
                
                //合并两个有序链表
                int x = 0, y = 0;
                while (x < i && y < i && p && q) {
                    if (p->val <= q->val) cur = cur->next = p, p = p->next, x ++ ;
                    else cur = cur->next = q, q = q->next, y ++ ;
                }
                while (x < i && p) cur = cur->next = p, p = p->next, x ++ ;
                while (y < i && q) cur = cur->next = q, q = q->next, y ++ ;
                
                //下一对左右区间, 左区间的起点是q
                cur->next = q;
            }
        }

        return dummy->next;
    }
};