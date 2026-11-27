class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for(int x : nums){
            ans += cnt[x]++;
        }
        return ans;
    }
};