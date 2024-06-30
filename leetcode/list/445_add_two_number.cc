// you are given two linked lists representing two non-negative numbers,
// the most significant digit comes first and each of their nodes
// caontain a single digit, add the two numbers and return it
// as a linked list.

ListNode* add_two_numbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    while (s1) {
        s.push(l1->val);
        l1 = l1->next;
    }

    while (l2) {
        s2.push(l2->val);
        l2 = l2->next;
    }
    int sum = 0;
    ListNode* res = new ListNode(0);
    while (!s1.empty()|| !s2.empty()) {
        if (!s1.empty()) {
            sum += s1.top();
            s1.pop();
        }
        if (!s2.empty()) {
            res->val = sum % 10;
            ListNode * head = new ListNode(sum / 10);
            head->next = res;
            res = head;
            sum /= 10;
        }
        return res->val == 0 ? res->next : res;
    }
}
