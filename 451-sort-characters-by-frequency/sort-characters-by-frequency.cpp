class Solution {
private:
    static bool comparator(pair<int, char> p1, pair<int, char> p2) {
        if (p1.first > p2.first) return true;
        if (p1.first < p2.first) return false;
        return p1.second < p2.second;
    }

public:
    string frequencySort(string s) {
        pair<int, char> freq[256];

        // initialize
        for (int i = 0; i < 256; i++) {
            freq[i] = {0, char(i)};
        }

        // count frequency
        for (char ch : s) {
            freq[(unsigned char)ch].first++;
        }

        // sort
        sort(freq, freq + 256, comparator);

        // build result
        string ans = "";
        for (int i = 0; i < 256; i++) {
            ans += string(freq[i].first, freq[i].second);
        }

        return ans;
    }
};
