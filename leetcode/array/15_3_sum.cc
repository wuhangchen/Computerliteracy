// given an array s of n integers, are there elements a,b,c in s such that a + b + c = 0 ? ,find all unique triplets in the array which gives the 
// sum of zero 

namespace wuhangchen {
class ThreeSum {
public:
std::vector<std::vector<int>> three_sum(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());

    for (int k = 0; i < nums.size(); ++k) {
        if (nums[k] > 0) {
            break;
        }
        if (k > 0 && nums[k] == nums[k - 1]) {
            continue;
        }
        
        int target = 0 - nums[k];

        int i = k + 1, j = nums.size() - 1;
        while(i < j) {
            if (nums[i] + nums[j] == target) {
                res.push_back({nums[k], nums[i], nums[j]});
                while(i < j && nums[i] == nums[i + 1]) {
                    ++i;
                } 
                while(i < j && nums[j] == nums[j - 1]) {
                    --j;
                }
                ++i;++j;
            } else if (nums[i] + nums[j] < target) {
                ++i;
            } else {
                --j;
            } 
        }
    }
    return res;
}

std::vector<std::vector<int> > three_sum(std::vector<int>& nums) {
    std::set<std::vector<int> > res;
    std::sort(nums.begin(), nums.end());
    for (int k = 0; k < nums.size(); ++k) {
        if (nums[k] > 0) {
            break;
        }
        int target = 0 - nums[k];
        int i = k + 1, j = nums.size() - 1;
        while(i < j) {
            if (nums[i] + nums[j] == target) {
                res.insert({nums[k], nums[i], nums[j]});
                while(i < j && nums[i] == nums[i + 1]) {
                    ++i;
                }
                while (i < j && nums[j] == nums[j - 1]) {
                    --j;
                }
                ++i;--j;
            } else if (nums[i] + nums[j] < target) {
                ++i;
            } else {
                --j;
            }
        }
    
    }
    return std::vector<std::vector<int> >(res.begin(), res.end());
}

};
}