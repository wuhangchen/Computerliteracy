// given a array nums of n integers and an integer target
// ,find three integer in nums, such that the sum is closest 
// to target, return the sum of the three integers, you may 
// assume that each input would have exactly one solution

namespace wuhangchen {
class ThreeSumClosest {
public:
    int three_sum_closest(const std::vector<int>& nums, int target) {
        int closest = num[0] + num[1] + num[2];
        int diff = std::abs(closest - target);
        std::sort(nums.begin(), nums,end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int new_diff = std::abs(sum - target);
                if (diff > new_diff) {
                    diff = new_diff;
                    closest = sum;
                }
                if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
            return closest;
        }
    }
};

int three_sum_closest(std::vector<int>& nums, int target) {
    int closest = nums[0] + nums[1] + nums[2];
    int diff = std::abs(closest - target);
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
        if (nums[i] * 3 > target) {
            return std::min(closest, nums[i] + nums[i + 1] + nums[i + 2]);
        }
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int new_diff = std::abs(sum - target);
            if (diff > new_diff) {
                diff = new_diff;
                closest = sum;
            } 
            if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
}
}