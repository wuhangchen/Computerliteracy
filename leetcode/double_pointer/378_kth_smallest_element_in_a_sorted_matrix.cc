// given a n*n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element 
// in the matrix

int kth_smallest(std::vector<std::vector<int>>& matrix, int k) {
    std::priority_queue<int> q;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            q.emplace(matrix[i][j]);
            if (q.size() > k) {
                q.pop();
            }
        }
    }
    return q.top();
}
