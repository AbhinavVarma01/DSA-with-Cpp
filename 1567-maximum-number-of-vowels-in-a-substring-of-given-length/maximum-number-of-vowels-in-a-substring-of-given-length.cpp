class Solution {
public:

    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    int maxVowels(string s, int k) {
        int count = 0;
        int maxV = 0;
        int n = s.size();
        for(int i=0; i<k; i++){
            if(isVowel(s[i])) count++;
        }
        maxV = count;

        for(int i=k; i<n; i++){
            if(isVowel(s[i-k])) count--;
            if(isVowel(s[i])) count++;

            maxV = max(maxV, count);
            if(maxV==k) return k;
        }
        return maxV;
    }
};