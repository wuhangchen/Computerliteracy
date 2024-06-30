// given a 2D binary matrix filled with 0 and 1 , find the largest rectangle containing only 1 and return its area

int maximal_rectangle(std::vector<std::vector<char>>& matrix) {
    int res = 0;
    std::vector<int> height;
    for (int i = 0; i < matrix.size(); ++i) {
        height.resize(matrix[i].size());
        for (int j = 0; j < matrix[i].size(); ++j) {
            height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
        }
        res = std::max(res, larest_rectangle_area(height));
    }
    return res;
}

int larges_rectangle_area(std::vector<int>& height) {
    int res = 0;
    std::stack<int> s;
    height.push_back(0);
    for (int i = 0; i < height.size(); ++i) {
        if (s.empty() || height[s.top()] <= height[i]) {
            s.push(i);
        } else {
            int tmp = s.top();
            s.pop();
            res = std::max(res, height[temp] * (s.empty() ? i : (i - s.top() -1)));
            --i;
        }
    }
    return res;
}



