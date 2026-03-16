class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        set<int> st;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                st.insert(g[i][j]); // size 0

                for(int k=1;;k++){
                    if(i-k<0 || i+k>=m || j-k<0 || j+k>=n) break;

                    int sum = 0;

                    for(int t=0;t<k;t++) sum += g[i-k+t][j+t]; // top-right
                    for(int t=0;t<k;t++) sum += g[i+t][j+k-t]; // right-bottom
                    for(int t=0;t<k;t++) sum += g[i+k-t][j-t]; // bottom-left
                    for(int t=0;t<k;t++) sum += g[i-t][j-k+t]; // left-top

                    st.insert(sum);
                }
            }
        }

        vector<int> v(st.begin(), st.end());
        reverse(v.begin(), v.end());
        if(v.size()>3) v.resize(3);
        return v;
    }
};