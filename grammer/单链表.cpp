#include<iostream>

using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int _val) : val(_val),next(NULL) {}
};

int main()
{
    Node* p =new Node(1);
    auto q = new Node(2);
    auto o = new Node(3);
    p->next = q;
    q->next = o;
    auto dummy = new Node(-1);
    dummy->next = p;
    auto cur = dummy;

    while(cur)
    {
        cout << cur->val << endl;
        cur = cur->next;
    }
    return 0;
}