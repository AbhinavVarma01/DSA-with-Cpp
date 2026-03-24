class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int count = 1;
        vector<char> res;

        for(int i=1; i<=n; i++){
            if(i<n && chars[i]==chars[i-1]) count++;
            else{
                res.push_back(chars[i-1]);
                if(count>1){
                    string s = to_string(count);
                    for(char c : s){
                        res.push_back(c);
                        count = 1;
                    }
                }
            }
        }
        chars = res;
        return chars.size();
    }
};