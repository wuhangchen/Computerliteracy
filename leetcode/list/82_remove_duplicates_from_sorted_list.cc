// given a sorted linked list, delete all nodes that have 
// duplicate numbers , leaving only distinct numbers from the original list

ListNode* delete_dup(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    ListNode* pre = dummy;

    dummy->next = head;
    while (pre->next) {
        ListNode* cur = pre->next;
        while (cur->next && cur->next->val == cur->val) {
            cur = cur->next;
        }
        if (cur != pre->next) {
            pre->next = cur->next;
        } else {
            pre = pre->next;
        }
        return dummy->next;
    }
}