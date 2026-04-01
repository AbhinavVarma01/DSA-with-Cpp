class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string d) {
        int n = pos.size();

        vector<pair<int,int>> robots; 
        for (int i = 0; i < n; i++) {
            robots.push_back({pos[i], i});
        }

        sort(robots.begin(), robots.end());

        stack<int> st;

        for (auto &it : robots) {
            int i = it.second;

            if (d[i] == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && d[st.top()] == 'R' && h[i] > 0) {
                    int j = st.top();

                    if (h[j] > h[i]) {
                        h[j]--;
                        h[i] = 0;
                    } else if (h[j] < h[i]) {
                        h[i]--;
                        h[j] = 0;
                        st.pop();
                    } else {
                        h[i] = h[j] = 0;
                        st.pop();
                    }
                }
                if (h[i] > 0) st.push(i);
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (h[i] > 0) res.push_back(h[i]);
        }

        return res;
    }
};