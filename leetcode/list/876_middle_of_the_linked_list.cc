// Given a non-empty, signle linked list with head node head, return a middle node of linked list
// if there are two middle nodes, return the second middle node.

ListNode* middle_node(ListNode* head) {
    ListNode* cur = head;
    int cnt = 0;
    while (cur) {
        ++cnt;
        cur = cur->next;
    }
    cnt /= 2;
    while (cnt > 0) {
        --cnt;
        head = head->next;
    }
    return head;
}

ListNode* middle_node_second(ListNode* head) {
    std::vector<ListNode*> vec(100);
    int cur = 0;
    while (head) {
        vec[cur++] = head;
        head = head->next;
    }
    return vec[cur / 2];
}

ListNode* middle_node_three(ListNode* head) {
    ListNode* slow = head;
    while (head && head->next) {
        slow = slow->next;
        head = head->next->next;
    }
    return slow;
}
