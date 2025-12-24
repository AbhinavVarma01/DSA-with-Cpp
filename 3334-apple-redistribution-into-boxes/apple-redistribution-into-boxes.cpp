class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int boxes = 0;
        sort(capacity.rbegin(), capacity.rend());
        int sum = accumulate(apple.begin(), apple.end(), 0);
        for(int i=0; i<capacity.size(); i++){
            if(sum<=0) break;
            sum -= capacity[i];
            boxes++;
            }
        return boxes;
    }
};