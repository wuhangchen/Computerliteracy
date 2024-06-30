// given an array, rorate the array to the right by k steps,
// where k is non-negative

void rotate(std::vector<int>& nums, int k) {
    std::vector<int> t = nums;
    for (int i = 0; i < nums.size(); ++i) {
        nums[(i + k) % nums.size()] = t[i];
    }
}
void totate(std::vector<int>& nums, int k) {
    if (nums.empty() || (k %= nums.size()) == 0) {
        return;
    }
    int n = nums.size();
    std::reverse(nums.begin(), nums.begin() + n - k);
    std::reverse(nums.begin() + n - k, nums.end());
    std::reverse(nums.begin(), nums.end());
}

void rotate(std::vector<int>& nums, int k) {
    if (nums.empty() || (k %= nums.size() == 0)) {
        return;
    }
    int n = nums.size();
    for (int i = 0; i < n - k; ++i) {
        nums.push_back(nums[i]);
        nums.erase(nums.begin());
    }
}