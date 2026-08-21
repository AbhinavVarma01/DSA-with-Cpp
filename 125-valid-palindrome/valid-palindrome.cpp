class Solution {
public:
    bool isPalindrome(string s) {
        string alphaNum ="";
        for(char ch : s){
            if(isalnum(ch)){
                alphaNum+= tolower(ch);
            }
        }
        int left = 0;
        int right = alphaNum.size()-1;
        while(left<right){
            if(alphaNum[left]!=alphaNum[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};