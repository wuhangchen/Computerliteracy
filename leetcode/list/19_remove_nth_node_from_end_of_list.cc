// given a linked list, remove the n the node from the end of list and 
// return its head 

ListNode* remove_nth_form_end(ListNode* head, int n) {
    if (!head->next) {
        return nullptr;
    }
    ListNode* pre = head;
    ListNode* cur = head;
    for (int i = 0; i < n; ++i) {
        cur = cur->next;
    }
    if (!cur) {
        return head->next;
    }
    while (cur->next) {
        cur = cur->next;
        pre = pre->next;
    }
    pre->next = pre->next->next;
    return head;
}