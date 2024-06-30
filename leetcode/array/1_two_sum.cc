//-+-------------------------------------------------------------------------------------------------------------------------------------+
// |two sum                                                                                                                              |
// |given an array of integers, and indices of the two numbers such that they add up to a speciific target                               |
// |you may assume that each input would have exactly one solution, and you may not use the same element twice                           |
// |                                                                                                                                     |
// |example                                                                                                                              |
// |given nums = [2, 7, 11, 15], target = 9;                                                                                             |
// |because nums[0] + nums[1] = 9,                                                                                                       |
// |return [0, 1]                                                                                                                        |
//-+-------------------------------------------------------------------------------------------------------------------------------------+

namespace wuhangchen {
class TwoSum {
public:
    std::vector<int> two_sum_one(const vector<int>& nums, const int target) {
    
        std::unordered_map<int, int> m;
        std::vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int t = target - num[i];
            if (m.count(t) && m[t] != i) {
                res.push_back(i);
                res.push_back(m[t]);
                break;
            }
        }

        return res;
    }

    std::vector<int> two_sum_two(const vector<int>& nums, const int target) {
        std::unordered_map<int, int> m;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(m.count(target - nums[i])) {
                return {i, m[target - nums[i]]};
            }
            m[nums[i]] = i;
        }

    }

};

}
