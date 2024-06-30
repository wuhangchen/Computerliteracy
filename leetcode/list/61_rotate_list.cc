// given a list, rotate the list to the right by k places.
// where k is non-negative

ListNode* rotate_right(ListNode* head, int k) {
    if (!head) {
        return null_ptr;
    }
    int n = 0;
    ListNode* cur = head;
    while (cur) {
        ++n;
        cur = cur->next;
    }
    k %= n;
    ListNode* fast = head;
    ListNode* slow = head;
    for (int i = 0; i < k; ++i) {
        if (fast) {
            fast = fast->next;
        }
    }
    if (!fast) {
        return head;
    }
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = head;
    fast = slow->next;
    slow->next = nullptr;
    return fast;
}

ListNode* rotate_right(ListNode* head, int k) {
    if (!head) {
        return nullptr;
    }
    int n = 1;
    ListNode* cur = head;
    while (cur->next) {
        ++n;
        cur = cur->next;
    }
    cur->next = head;
    int m = n - k % n;
    for (int i = 0; i < m; ++i) {
        cur = cur->next;
    }
    ListNode* new_head = cur->next;
    cur->next = null_ptr;
    return new_head;
}