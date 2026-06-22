class Solution {
public:

    vector<int> findNSE(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSE(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int sum = 0;
        int mod = 1e9+7;
        int n = arr.size();
        for(int i=0; i<n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            long long freq = left*right*1LL;
            int val = (freq*arr[i]) % mod;
            sum = (sum + val) % mod;
        }
        return sum;
    }
};