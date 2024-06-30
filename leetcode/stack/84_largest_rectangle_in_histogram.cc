// given n non-negative integers representing the histogram bar height where the width of each bar is 1, 
// find the area of largest rectangle in the histogram.

int largest_rectangle_area(std::vector<int>& height) {
    int res = 0;
    std::stack<int> s;
    height.push_back(0);
    for (int i = 0; i < height.size(); ++i) {
        if (s.empty() || height[s.top()] < height[i]) {
            s.push(i);
        } else {
            int cur = s.top();
            s.pop();
            res = std::max(res, height[cur] * (s.empty() ? i : (i - s.top() -1)));
            --i;
        }
    }
    return res;
}

