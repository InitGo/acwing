    Node* p =new Node(1);
    auto q = new Node(2);
    auto o = new Node(3);
    p->next = q;
    q->next = o;
    return 0;
    auto dummy = new Node(-1);
    dummy->next = p;
    auto cur = dummy;