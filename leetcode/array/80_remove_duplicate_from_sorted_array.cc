// given a sorted array , remove the duplicates in-place 
// such that duplicates appeared at most twice and return the new length.

int remove_duplicates(std::vector<int>& nums) {
    int len = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (len < 2 || nums[i] != nums[i - 2]) {
            nums[len++] = nums[i];
        }
    }
    return len;
}