class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int total = 0;

        for (int w : worker) {
            int best = 0;
            for (int i = 0; i < difficulty.size(); i++) {
                if (w >= difficulty[i]) {
                    best = max(best, profit[i]);
                }
            }
            total += best;
        }

        return total;
    }
};