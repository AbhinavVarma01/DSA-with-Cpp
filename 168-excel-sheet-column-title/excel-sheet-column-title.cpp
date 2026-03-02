class Solution {
public:
    string convertToTitle(int columnNumber) {
        if(columnNumber == 0) return "";
        columnNumber--;
        string ans = convertToTitle(columnNumber/26);
        char sol = ('A' + (columnNumber%26));
        return ans + sol;
    }
};