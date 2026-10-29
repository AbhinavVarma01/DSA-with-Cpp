
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> depth(n), tin(n), tout(n), pref(n);

        auto getMask = [](char c) {
            return 1 << (c - 'a');
        };

        // DFS using a stack
        int timer = 0;
        vector<array<int, 3>> st;
        st.push_back({0, 0, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.back();
            st.pop_back();

            if (state == 1) {
                tout[u] = timer;
                continue;
            }

            tin[u] = ++timer;
            up[0][u] = p;
            pref[u] = (u == 0 ? 0 : pref[p]) ^ getMask(s[u]);

            for (int j = 1; j < LOG; j++)
                up[j][u] = up[j - 1][up[j - 1][u]];

            st.push_back({u, p, 1});

            for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];
                if (v == p) continue;

                depth[v] = depth[u] + 1;
                st.push_back({v, u, 0});
            }
        }

        // Fenwick Tree for XOR updates
        vector<int> bit(n + 2);

        auto add = [&](int i, int val) {
            while (i <= n + 1) {
                bit[i] ^= val;
                i += i & -i;
            }
        };

        auto sum = [&](int i) {
            int res = 0;
            while (i > 0) {
                res ^= bit[i];
                i -= i & -i;
            }
            return res;
        };

        // Find Lowest Common Ancestor
        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++)
                if (diff & (1 << j))
                    u = up[j][u];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        vector<bool> ans;

        for (string q : queries) {
            string type;
            int u;
            char c;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;

                int change = getMask(s[u]) ^ getMask(c);

                // Update all prefixes in u's subtree
                add(tin[u], change);
                add(tout[u] + 1, change);

                s[u] = c;
            } else {
                int v;
                ss >> v;

                int pu = pref[u] ^ sum(tin[u]);
                int pv = pref[v] ^ sum(tin[v]);

                int w = lca(u, v);

                int pathMask = pu ^ pv ^ getMask(s[w]);

                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};
