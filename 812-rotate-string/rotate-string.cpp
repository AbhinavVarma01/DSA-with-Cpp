class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!= goal.size()) return false;
        string doubleStr = s + s;
        return doubleStr.find(goal)!= string::npos;
    }
};