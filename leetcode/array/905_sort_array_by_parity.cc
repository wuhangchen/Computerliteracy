// given an array of A non-negative integers. return an array 
// consisting of all the even elements of A, followed by all the odd elements of A 

std::vector<int> sort_array(std::vector<int>& A) {
    std::vector<int> even, odd;
    for (auto num : A) {
        if (num % 2 == 0) {
            even.push_back(num);
        } else {
            odd.push_back(num);
        }
    }
    even.insert(even.end(), odd.begin(), odd.end());
    return even;
}

std::vector<int> sort_array(std::vector<int>& A) {
    for (int i = 0, j = 0; j < A.size(); ++j) {
        if (A[j] % 2 == 0) {
            std::swap(A[i++], A[j]);
        } 
    }
    return A;
}

std::vector<int> sort_array(std::vector<int>& A) {
    std::partition(A.begin(), A.end(), [](auto a) {return a % 2 == 0;});
    return A;
}