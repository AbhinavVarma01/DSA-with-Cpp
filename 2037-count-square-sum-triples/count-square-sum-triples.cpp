class Solution {
public:
    int countTriples(int n) {
        vector<int> squares;
        for(int i=1; i<=n; i++){
            squares.push_back(i*i);
        }
        int count = 0;
        for(int a=1; a<=n; a++){
            for(int b=1; b<=n; b++){
                int sum = a*a + b*b;

                if(binary_search(squares.begin(), squares.end(), sum)){
                    count++;
                }
            }
        }
        return count;
    }
};