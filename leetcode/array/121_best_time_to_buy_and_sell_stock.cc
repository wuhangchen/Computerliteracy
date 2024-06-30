// say you have an array for which the i the elemnts is the 
// the price of a given stock on day i

int max_profit(std::vector<int>& prices) {
    int res = 0;
    int buy = INT_MAX;
    for (auto price : prices) {
        buy = std::min(buy, prices);
        res = std::max(res, price - buy);
    } 
    return res;
}