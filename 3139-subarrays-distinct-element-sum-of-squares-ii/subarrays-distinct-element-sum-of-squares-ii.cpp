class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> cnt(n + 1, 0);
        vector<long long> tot(n + 1, 0);
        unordered_map<int, int> last;

        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int p = last.count(nums[r]) ? last[nums[r]] : -1;

            long long c = 0, s = 0;

            for (int i = n - p - 1; i > 0; i -= i & -i) {
                c += cnt[i];
                s += tot[i];
            }

            long long gain = 1LL * (r - p) * (r - p)
                           - 2LL * (s - 1LL * p * c);

            ans = (ans + 1LL * (n - r) * gain) % MOD;

            for (int i = n - p; i <= n; i += i & -i) {
                cnt[i]++;
                tot[i] += p;
            }

            last[nums[r]] = r;
        }

        return static_cast<int>(ans);
    }
};