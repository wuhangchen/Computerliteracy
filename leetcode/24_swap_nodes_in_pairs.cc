// given a linked list, swap every two adjacent nodes and return its head.

ListNode* swap_pairs(ListNode* head) {
    ListNode* dummy = new ListNode(-1);
    ListNode* pre = dummy;

    dummy->next = head;
    while(pre->next && pre->next->next) {
        ListNode* t = pre->next->next;
        pre->next->next = t->next;
        t->next = pre->next;
        pre->next = t;
        pre = t->next;
    }
    return dummy->next;
}

ListNode* swap_pairs(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* t = head->next;
    head->next = swap_pairs(head->next->next);
    t->next = head;
    return t;
}
