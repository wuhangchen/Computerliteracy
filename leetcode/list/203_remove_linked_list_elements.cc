// Remove all elememts from a linked list of integers that 
// have value val

ListNode* remove_elements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(-1);
    ListNode* pre = dummy;
    dummy->next = head;
    while (pre->next) {
        if (pre->next->val == val) {
            ListNode* t = pre->next;
            pre->next = t->next;
            t->next = nullptr;
            delete t;
        } else {
            pre = pre->next;
        }
    }
}
