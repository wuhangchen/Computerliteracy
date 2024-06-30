// find the contiguous subarray within an array(containing at least one number)which has the largest sum 

int max_sub_array(std::vector<int>& nums) {
    int res = INT_MIX, cur_sum = 0;
    for (int num : nums) {
        cur_sum = max(cur_sum + num, num);
        res = max(res, cur_sum);
    }
    return res;
}


int max_sum_array(std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    return helper(nums, 0, (int)nums.size() - 1);
}

int helper(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
        return nums[left];
    }

    int mid = left + (right - left) / 2;
    int lmax = helper(nums, left, mid - 1);
    int rmax = helper(nums, mid + 1, right);
    int mmax = nums[mid], t = mmax;

    for (int i = mid -1; i >= left; --i) {
        t += nums[i];
        mmax = max(mmax, t);
    }

    t = mmax;
    for (int i = mid +1; i <= right; ++i) {
        t += nums[i];
        mmax = max(mmax, t);
    }
    return max(mmax, max(lmax, rmax));
}
