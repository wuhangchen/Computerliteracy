// suppose an array sorted in ascending order is rotated at some 
// pivot unknown to you beforhand

bool search(std::vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return true;
        } else if (nums[mid] < nums[right]) {
            if (nums[mid] < target && nums[right] >= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else if (nums[mid] > nums[right]) {
            if (nums[left] <= target && nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            --right;
        }
    }
    return false;
}