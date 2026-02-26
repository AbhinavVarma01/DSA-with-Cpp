class Solution {
public:

    void func(int index, string digits, string s, vector<string> &ans, string combos[]){
        if(index==digits.size()){
            ans.push_back(s);
            return;
        }

        int digit = digits[index] - '0';

        for(int i=0; i<combos[digit].size(); i++){
            func(index+1, digits, s+combos[digit][i], ans, combos);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s = "";
        func(0,digits, s, ans, combos);
        return ans;
    }
};