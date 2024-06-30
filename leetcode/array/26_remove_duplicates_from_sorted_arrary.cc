// given a sorted array nums, remove the duplicates in-place
// such that each element appear only once and return the new 
// lenght .Do not allocate extra space for another array .
// you must do this by modifying the input arrary in-place wih
// O(1) extra memory

namespace wuhangchen {
class RemoveDuplicateFromSortArray {
public:
    int remove_dup(std::vector<int>& nums) {
        int pre = 0;
        int cur = 0;
        int n = nums.size();
        while (cur < n) {
            if (nums[pre] == nums[cur]) {
                ++cur;
            } else {
                nums[++pre] = nums[cur++];
            }
        }
        return nums.empty() ? 0 : (pre + 1);
    }
    int remove_dup_second(std::vector<int>& nums) {
        int j = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != nums[j]) {
                nums[++j] = nums[i];
            }
        }
        return nums.empty() ? 0 : (j + 1);
    }
    int remove_dup_third(std::vector<int>& nums) {
        int i = 0;
        for (int num : nums) {
            if (i < 1 || num > nums[i - 1]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};

} // namespace wuhangche class RemoveDuplicateFromSortArray {
