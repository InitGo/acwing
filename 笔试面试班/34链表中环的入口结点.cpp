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
    ListNode *entryNodeOfLoop(ListNode *head) {
        if (!head || !head->next) return 0;
        ListNode *first = head, *second = head;

        while (first && second) //如果为空，说明没有环，直接返回
        {
            first = first->next;
            second = second->next;
            if (second) second = second->next; //如果second存在，多走一步
            else return 0; //否则说明second走到了空，没有环，返回

            if (first == second) //在c点相遇
            {
                first = head; //first从头开始走
                while (first != second) //，每次两个指针都走一步，相遇在b点
                {
                    first = first->next;
                    second = second->next;
                }
                return first;
            }
        }

        return 0;
    }
};