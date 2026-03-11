class Solution {
public:
    int findComplement(int num) {
        if(num==0) return 1;
        int ans = 0;
        int i = 0;
        while(num>0){
            int bit = num%2;
            if(bit==0){
                ans+= pow(2,i);
            }
            i++;
            num = num/2;
        }
        return ans;
    }
};