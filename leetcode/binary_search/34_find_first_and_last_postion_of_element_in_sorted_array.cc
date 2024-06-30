// given an array of integer nums sorted in ascending order.
// find the starting and ending position of a given target
// value , your algorightm's runtime complexity must 
// be in the order of O(log n)

namespace wuhangchen {
class FirstAndLastPost {
public:
    std::vector<int> search_range(std::vector<int>& nums, int taget) {
        int idx = search(nums, 0, nums.size() - 1, target);
        if (idx == -1) {
            return {-1, -1};
        }
        int left = idx;
        int right = idx;
        while (left > 0 && nums[left - 1] == nums[idx]) {
            --left;
        }
        while (right > 0 && nums[right + 1] == nums[idx]) {
            ++right;
        }
        return {left, right};
    }
    int serach (std::vector<int>& nums, int left, int right, int tagert) {
        if (left > right) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            return search(nums, mid + 1, right, target);
        } else {
            return search(nums, left, mid - 1, target);
        }
        
    }
};
}