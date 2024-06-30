/*
 * input {2, 7, 11, 15}
 * target 9
 * output {1, 2}
 */


std::vector<int> two_sum(std::vector<int>& numbers, int taget) {
    int l = 0; 
    int r = numbers.size() - 1;
    while (l < r) {
        int sum = number[l] + numbers[r];
        if (sum == target) {
            return {l + 1, r + 1};
        } else if (sum < target) {
            ++l;
        } else {
            --r;
        }
    }
    return {};
}

std::vector<int> two_sum(std::vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size(); ++i) {
        int t = target - numbers[i];
        int left = i + 1;
        int right = numbers.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] == t) {
                return {i + 1, mid + 1};
            } else if (numbers[mid] < t) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
    }
    return {};
}
