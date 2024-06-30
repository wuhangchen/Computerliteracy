// given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

struct ListNode {

    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(nullptr) {}
};

ListNode* reverse_k_group(ListNode* head, int k) {
    if (!head || k == 1) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    ListNode* pre = dummy, *cur = head;
    dummy->next = head;

    int i = 0;
    while(cur) {
        ++i;
        if (i % k == 0) {
            pre = reverse_one_group(pre, cur->next);
            cur = pre->next;
        } else {
            cur = cur->next;
        }
    }

    return dummy->next;
}

ListNode* reverse_one_group(ListNode* pre, ListNode* next) {
    ListNode* last = pre->next;
    ListNode* cur = last->next;

    while(cur != next) {
        last->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = last->next;
    }
    return last;

}


// 1 2 3 4 5    k = 3
// -1 1 2 3 4 5 


ListNode* reverse_k_group(ListNode* head, int k) {
    ListNode* dummy = new ListNode(-1);
    ListNode* pre = dummy;
    ListNode* cur = pre;

    dummy->next = head;
    int num = 0;
    while (cur = cur->next) {
        ++num;
    }

    while (num >= k) {
        cur = pre->next;
        for (int i = 1; i < k; ++i) {
            ListNode* t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;
        } 
        pre = cur;
        num -= k;
    }
    return dummy->next;
}
