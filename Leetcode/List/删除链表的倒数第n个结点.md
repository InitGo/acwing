
- 同时存前驱和目标节点
```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        for (auto p = head; p; p = p->next) len ++ ;  //计算链表的长度
        
        auto cur = head; 
        ListNode* pre = nullptr; //前驱节点初始化指向nullptr
        for (int i = 0; i < len - n; i ++ )  //倒数第n个点，正数第len-n+1个点，遍历len-n次【第一个点，遍历0次，第k个点，遍历k-1次】
        {
            pre = cur; //pre存前驱节点
            cur = cur->next;
        }
        if (!pre) return head->next; //如果pre为空，说明cur指向head
        else {
            pre->next = pre->next->next;
        }
        return head;
    }
};
```

- 虚拟头节点
```c++

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        for (auto p = head; p; p = p->next) len ++ ;

        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto cur = dummy;
        for (int i = 0; i < len - n; i ++ ) 
            cur = cur->next;
            
        cur->next = cur->next->next;

        auto p = dummy->next;
        delete dummy;
        return p;
    }
};
```