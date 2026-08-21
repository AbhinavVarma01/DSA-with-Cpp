class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hashh(256, 0);

        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++) {

            hashh[s[right]]++;

            while(hashh[s[right]] > 1) {
                hashh[s[left]]--;
                left++;
            }

            int len = right - left + 1;
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};