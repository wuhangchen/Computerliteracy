// write a program to find the node at which the intersection
// of two singly linked lists begins

ListNode* get_intersection_node(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) {
        return NULL:
    }
    ListNode* a = headA;
    ListNode* b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

int get_length(ListNode* head) {
    int cnt = 0;
    while (head) {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

ListNode* get_intersection_node(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) {
        return nullptr;
    }
    int lenA = get_length(headA);
    int lenB = get_length(headB);
    if (lenA < lenB) {
        for (int i = 0; i < lenB - lenA; ++i) {
            headB = headB->next;
        }
    } else {
        for (int i = 0; i < lenA - lenB; ++i) {
            headA = headA->next;
        }
    }
    while (headA && headB && headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }
    return (headA && headB) ? headA : nullptr;
}