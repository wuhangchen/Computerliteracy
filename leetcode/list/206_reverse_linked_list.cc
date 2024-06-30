// reverse a singly linked list

ListNode* reverse_list(ListNode* head) {
    ListNode* new_head = nullptr;
    while (head) {
        ListNode* t = head->next;
        head->next = new_head;
        new_head = head;
        head = t;
    }
    return new_head;
}

ListNode* reverse_list(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* new_head = reverse_list(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}

ListNode* reverse_list(ListNode* head) {
    std::stack<int> s;
    while (head) {
        s.push(head->val);
        head = head->next;
    }
    ListNode* res = new ListNode(-1);
    ListNode* p = res;
    while (!s.empty()) {
        p->next = new ListNode(s.top());
        s.pop();
        p = p->next;
    }
    return res->next;
}