//given array where elements are sorted in ascending coder ,
//convert it to a height balanced bst 

TreeNode* sorted_array_to_bst(std::vector<int>& nums) {
    return sorted_array_to_bst(num, 0, nums.size() - 1);
}
TreeNode* sorted_array_to_bst(std::vector<int> nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    int mid = (left + right) / 2;
    TreeNode* cur = new TreeNode(mid);

    cur->left = sorted_array_to_bst(nums, left, mid - 1);
    cur->right = sorted_array_to_bst(nums, mid + 1, right);
    return cur;
}