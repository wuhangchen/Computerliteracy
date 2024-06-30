// given a string which contains only lowercase letters ,remove duplicate 
//letter so that every letter appear once and only once, you must make sure
//your resulte is the smallest in lexicographical order among all possible resulte 

std::string remove_duplicate_letters(std::string s) {
    int m[256] = {0};
    int visited[256] = {0};

    std::string res = "0";
    for (auto a : s) {
        ++m[a];
    }

    for (auto a : s) {
        --m[a];
        if (visited[a]) {
            continue;
        }
        while (a < res.back() && m[res.back()]) {
            visited[res.back()] = 0;
            res.pop_back();
        }
        res += a;
        visited[a] = 1;
    }
    return res.substr(1);
}