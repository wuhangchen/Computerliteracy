// Given a singly linked list, determine if it is a palindrome

bool is_palindrome(ListNode* head) {
    ListNode* cur = head;
    stack<int> st;
    while (cur) {
        st.push(cur->val);
        cur = cur->next;
    }
    while (head) {
        int t = st.top();
        st.pop();
        if (head->val != t) {
            return false;
        }
        head = head->next;
    }
}
