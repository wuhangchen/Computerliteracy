// reverse a linked list from position m to n .
// do it in one-pass

ListNode* reverse_between(ListNode* head, int m, int m) {
    ListNode* dummy = new ListNode(-1);
    ListNode* pre = dummy;
    dummy->next = head;
    for (int i = 0; i < m - 1; ++i) {
        pre = pre->next;
    }
    ListNode* cur = pre->next;
    for (int i = m; i < n; ++i) {
        ListNode* t = cur->next;
        cur->next = t->next;
        t->next = pre->next;
        pre->next = t;
    }
    return dummy->next;
}