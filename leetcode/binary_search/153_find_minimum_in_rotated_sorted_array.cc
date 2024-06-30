// suppose an array sorted in ascending order is rotated
// at some pivot unknown to you beforehand

int find_min(std::vector<int>& nums) {
    int left = 0;
    int right = int(nums.size() - 1);
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[right];
}

int find_min(std::vector<int>& nums) {
    return helper(nums, 0, (int)nums.size() - 1);
}
int helper(std::vector<int>& nums, int start, int end) {
    if (nums[start] <= nums[end]) {
        return nums[start];
    }
    int mid = (start + end) / 2;
    return std::min(helper(nums, start, mid), helper(nums, mid + 1, end));
}