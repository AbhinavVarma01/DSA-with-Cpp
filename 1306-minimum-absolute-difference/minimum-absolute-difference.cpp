class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        int n = arr.size();

        for(int i=1; i<n; i++){
            minDiff = min(minDiff, arr[i]-arr[i-1]);
        }

        for(int i=1; i<n; i++){
            if(arr[i]-arr[i-1]==minDiff){
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        return ans;
    }
};