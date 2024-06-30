// given an array of integers, find if the array contains 
// any duplicates , you function should return true if any value 
// appeares at leaset twice in the array . and it should return false
// if every element is distinct 

bool contain_dup(std::vector<int>& nums) {
    std::unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        if (m.find(nums[i] != m.end())) {
            return true;
        }
        ++m[nums[i]];
    }
    return false;
}

bool contain_dup(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }
    return false;
}