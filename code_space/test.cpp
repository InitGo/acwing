linklist delete(linklist *head, int k)
{
    int len = 0;
    for (auto p = head; p; p = p->next) len ++ ;

    auto dummy = new listnode();
    dummy->next = head;
    
    auto a = dummy;
    for (int i = 0; i < len - k; i ++ ) a = a->next;
    a->next = a->next->next;
    return dummy->next;

}