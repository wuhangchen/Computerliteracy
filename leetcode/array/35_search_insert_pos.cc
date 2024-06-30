// search insert position
// Given a sorted array and a target value, return the index
// if the index if the target is found , if not, return the index 
// where it would be if it were inserted in order

namespace wuhangchen {
class SearchInsertPos {
public:
    int search_insert(const std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= target) {
                return i;
            }
        }
        return nums.size();
    }

    int seach_insert(const std::vector<int>& nums, int target) {
        if (nums.back() < target) {
            return nums.size();
        }
        int left = 0; 
        int right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }
};
}