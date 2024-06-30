// sort a linked list in O(nlogn) time using constant space 
// complexity

ListNode* sort_list(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* pre = head;
    while (fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = nullptr;
    return merge(sort_list(head), sort_list(slow));
}

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;

    while(l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1) {
        cur->next = l1;
    }
    if (l2) {
        cur->next = l2;
    }
    return dummy->next;
}

ListNode* merge(ListNode* l1, ListNode* l2) {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }
    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
} 