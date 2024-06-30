// given an integer array nums, find the contiguous subarray 
// which has the largest sum and return its sum 

int max_subarrary(std::vector<int>& nums) {
    int res = INT_MIN;
    int curSum = 0;

    for (auto num : nums) {
        curSum = std::max(curSum + num, num);
        res = std::max(res, curSum);
    }
    return res;
}

int max_subarray(std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    return helper(nums, 0, int(nums.size() - 1));
}

int helper(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
        return nums[left];
    }
    int mid = left + (right - left) / 2;
    int lmax = helper(nums, left, mid - 1);
    int rmax = helper(nums, mid + 1, right);

    int mmax = nums[mid];
    int t = mmax;
    for (int i = mid - 1; i >= left; --i) {
        t += nums[i];
        mmax = std::max(mmax, t);
    }
    t = mmax;
    for (int i = mid + 1; i <= right; ++i) {
        t += nums[i];
        mmax = std::max(mmax, t);
    }
    return std::max(mmax, std::max(lmax, rmax));
}