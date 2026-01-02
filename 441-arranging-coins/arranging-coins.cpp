class Solution {
public:
    int arrangeCoins(int n) {
    //     int i=1;
    //     int res=0;
    //     while(i<=n){
    //         n-=i;
    //         i++;
    //         res++;
    //     }
    //     return res;
    // }

    return (int)((sqrt(1+8LL*n)-1)/2);
    }
};