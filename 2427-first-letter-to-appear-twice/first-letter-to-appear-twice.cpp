class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> st;
        for(char c : s){
            if(st.find(c)!=st.end()) return c;
            st.insert(c);
        }
        return '#';
    }
};