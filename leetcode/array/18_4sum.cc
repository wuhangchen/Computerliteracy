// given an arrary s of n integers are there elements a b
// c d in s such that a + b + c + d = target. find all unique 
// quadruplets in the arrary which gives the sum of taget
namespace wuhangchen {

class FourSum{
public:
std::vector<std::vector<int> > four_sum(std::vector<int>& nums, int target) {
    std::set<std::vector<int> > res;
    std::sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size() - 3; ++i) {
        for (int j = i + 1; j < nums.size() -2; ++j) {
            if (j > i + 1 && nums[j] == nums[j -1]){
                continue;
            }
            int left = j + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    std::vector<int> out{num[i], nums[j], nums[left], nums[right]};
                    res.insert(out);
                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
    }
    return std::vector<std::vector<int>>(res.begin(), res.end());
}
};
}