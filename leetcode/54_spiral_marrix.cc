// given a matrix of m * n elements , return all elements of the matrix in spiral order

std::vector<int> spiral_order(std::vector<std::vector<int>>& matrix) {
    std::vector<int> res;
    if (matrix.empty() || matrix[0].empty()) {
        return res;
    }

    int m = matrix.size();
    int n = matrix[0].size();
}
