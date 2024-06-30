//given a singly linked list where elements are sorted in ascending order, 
//convert it to a height balanced bst

TreeNode* sorted_list_to_bst(TreeNode* head) {
    if (!head) {
        return nullptr;
    }
    if (!head->next) {
        return new TreeNode(head->val);
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* last = slow;
    
    while (fast->next && fast->next->next) {
        last = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    last->next = nullptr;

    TreeNode* cur = new TreeNode(slow->val);
    if (head != slow) {
        cur->left = sorted_list_to_bst(head);
    }
    cur->right = sorted_list_to_bst(fast);
    return cur;
}