
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        bool negative = (dividend < 0) ^ (divisor < 0);
        long long ans = 0;

        while (a >= b) {
            long long temp = b;
            long long count = 1;

            while (a - temp >= temp) {
                temp += temp;
                count += count;
            }

            a -= temp;
            ans += count;
        }

        if (negative)
            ans = -ans;

        return (int)ans;
    }
};
