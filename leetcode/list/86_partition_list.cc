// given a linked list and a value x, partition it such that all nodes less than x come before nodes greater that or equal to x
// you should preserve the original relative orderof the nodes in each of the two partitions 

ListNode* partition(ListNode* head, int x) {
    if (!head) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    ListNode* new_dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* cur = dummy;
    ListNode* p = new_dummy;

    while (cur->next) {
        if (cur->next->val < x) {
            p->next = cur->next;
            p = p->next;
            cur->next = cur->next->next;
            p->next = nullptr;
        } else {
            cur = cur->next;
        }
    }
    p->next = dummy->next;
    return new_dummy->next;
}