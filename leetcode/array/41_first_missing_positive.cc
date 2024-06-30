// Given an unsoted integer array ,find the smallest missing positive integer

int first_missing_positive(std::vector<int>& nums) {
    std::unordered_set<int> st(nums.begin(), nums.end());

    int res = 1;
    int n = nums.size();

    while (res <= n) {
        if (!st.count(res)) {
            return res;
        }
        ++res;
    }
    return res;
}

int first_missing_positive(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[i] - 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;

}