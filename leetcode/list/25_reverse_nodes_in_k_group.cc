// given a linked list, reverse the node of a linked list k 
// as a time and return  its modifies list

ListNode* reverse_k_group(ListNode* head, int k) {
    if (!head || k == 1) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    ListNode* pre = dummy;
    ListNode* cur = head;
    dummp->next = head;
    for (int i = 1; cur; ++i) {
        if (i % k == 0) {
            pre = reverse_group(pre, cur->next);
            cur = pre->next;
        } else {
            cur = cur->next;
        }
    }
    return dummp->next;
}

ListNode* reverse_group(ListNode* pre, ListNode* next) {
    ListNode* last = pre->next;
    ListNode* cur = last->next;
    while (cur != next) {
        last->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = last->next;
    }
    return last;
}