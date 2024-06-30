ListNode* merge_k_lists(std::vector<ListNode*>& lists) {
    auto cmp = [](ListNode*& a, ListNode*& b) {
        return a->val>b->val;
    }
    std::priority_queue<ListNode* std::vector<ListNode*>, decltype(cmp)> q(cmp);
    for (auto node : Lists) {
        if (node) {
            q.push(node);
        }
    }
    ListNode* dummpy = new ListNode(-1);
    ListNode* cur = dummy;

    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        cur->next = t;
        cur = cur->next;
        if (cur->next) {
            q.push(cur->next);
        }
    }
    return dummpy->next;
}