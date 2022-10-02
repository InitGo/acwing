#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    //ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* create_list(const int q[], const int n)
{
    auto dummy = new ListNode(-1);
    auto cur = dummy;
    for (int i = 0; i < n; i ++ )
    {
        auto node = new ListNode(q[i]);
        cur = cur->next = node;
    }
    auto p = dummy->next;
    delete dummy;
    return p;
}

ListNode* reverseList(ListNode* head)
{
    auto cur = head;
    ListNode* prev = NULL;

    while (cur) {
        auto next = cur->next;
        cur->next = prev;
        prev = cur, cur = next;
    }
    return prev;
}


int main()
{
    int a[5] = {5, 4, 3, 2, 1};

    int b[] = {};

    auto head = create_list(a, 5);
    auto newhead = reverseList(head);

    if (!newhead) cout << "输入为空链表" << endl;
    else cout << "输入为非空链表" << endl;

    for (auto p = newhead; p; p = p->next) {
        cout << p->val << ' ';
    }

    return 0;
}