// given an array nums containing n + 1 integers where each integer is between 1 and n,
// prove that at least one duplicate number must exist, Assume that there is only one duplicate number,
// find the duplicate one

int find_duplicate(std::vector<int>& nums) {
    int left = 1;
    int right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        int cnt = 0;
        for (auto num : nums) {
            if (num <= mid) {
                ++cnt;
            }
        }
        if (cnt <= mid) {
            left + mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}

int find_duplicate(std::vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    int t = 0;

    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast) {
            break;
        }
    }
    while (true) {
        slow = nums[slow];
        t = nums[t];
        if (slow == t) {
            break;
        }
    }
    return slow;
}
