// sort a linked list using insertion sort 

ListNode* insertion_sort_list(ListNode* head) {
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;

    while (!head) {
        ListNode* t = head->next;
        cur = dummy;
        while (cur->next && cur->next->next) {
            cur = cur->next;
        }
        head->next = cur->next;
        cur->next = head;
        head = t;
    }
    return dummy->next;
}