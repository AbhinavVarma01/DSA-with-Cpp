class Solution {
public:
    long long picker(int n, int m, long long prod, vector<vector<int>>& grid) {
        if (n == 0 && m == 0) return prod * grid[0][0];
        if (prod == 0) return 0;

        long long up = (n != 0) ? picker(n - 1, m, prod * grid[n][m], grid) : LLONG_MIN;
        long long left = (m != 0) ? picker(n, m - 1, prod * grid[n][m], grid) : LLONG_MIN;

        return max(up, left);
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long ans = picker(n - 1, m - 1, 1, grid);

        if (ans < 0) return -1;
        return ans % 1000000007;
    }
};