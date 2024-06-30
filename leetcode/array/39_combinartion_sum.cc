// Given a set of candidate numbers and a target number 
// find all unique combinations in candiates 

namespace wuhangchen {
class CombinateSum {
public:
    std::vector<std::vector<int> > combination_sum(std::vector<int>& candiates, int target) {
        std::vector<std::vector<int> > res;
        std::vector<int> out;
        combination_sum_dfs(candiates, target, 0, out, res);
    }

    void combination_sum_dfs(std::vector<int>& candiates, int target, int start, std::vector<int>& out, std::vector<std::vector<int>>& res) {
        if (target < 0) {
            return ;
        }
        if (target == 0) {
            res.push_back(out);
            return;
        }
        for (int i = start; i < canidates.size(); ++i) {
            out.push_back(candidates[i]);
            combination_sum_dfs(candidates, target - candidates[i], i ,out, res);
            out.pop_back();
        }
    }
};
}