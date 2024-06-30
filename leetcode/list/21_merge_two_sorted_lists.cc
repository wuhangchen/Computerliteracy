// merge two sorted lists and return it as a new list. 
// the new list should be made by splicing together the 
// nodes of the first two lists

ListNode* merge_two_list(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return dummy->next;
}

ListNode* merge_two_list(ListNode* l1, ListNode* l2) {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }
    if (l1->val < l2->val) {
        l1->next - merge_two_list(l1->next, l2);
        return l1;
    } else {
        l2->next = merge_two_list(l1, l2->next);
        return l2;
    }
}