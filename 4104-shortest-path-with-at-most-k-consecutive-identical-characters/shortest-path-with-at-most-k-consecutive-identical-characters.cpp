class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (vector<int> e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        priority_queue<tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            tuple<int,int,int> p = pq.top();
            pq.pop();

            int w = get<0>(p);
            int node = get<1>(p);
            int con = get<2>(p);

            if (w > dist[node][con]) continue;

            if (node == n - 1) return w;

            for (pair<int,int> x : adj[node]) {

                int next = x.first;
                int cost = x.second;

                int c = (labels[node] == labels[next]) ? con + 1 : 1;

                if (c > k) continue;

                if (dist[next][c] > w + cost) {
                    dist[next][c] = w + cost;
                    pq.push({w + cost, next, c});
                }
            }
        }

        return -1;
    }
};