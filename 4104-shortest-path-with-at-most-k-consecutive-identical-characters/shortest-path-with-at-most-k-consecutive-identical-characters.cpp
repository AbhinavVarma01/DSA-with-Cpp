class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (vector<int> e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        const long long INF = LLONG_MAX;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        while (!pq.empty()) {
            tuple<long long, int, int> p = pq.top();
            pq.pop();
            long long w = get<0>(p);
            int node = get<1>(p);
            int con = get<2>(p);
            if (w > dist[node][con])
                continue;
            if (node == n - 1)
                return w;
            for (pair<int,int> kk : adj[node]) {
                int next = kk.first;
                int cost = kk.second;
                int newCount;
                if (labels[node] == labels[next])
                    newCount = con + 1;
                else
                    newCount = 1;
                if (newCount > k)
                    continue;
                long long newDist = w + cost;
                if (newDist < dist[next][newCount]) {
                    dist[next][newCount] = newDist;
                    pq.push({newDist, next, newCount});
                }
            }
        }
        return -1;
    }
};