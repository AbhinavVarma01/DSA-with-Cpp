class Fancy {
public:
    const long long M = 1e9+7;
    vector<long long> v;
    long long mul = 1, add = 0;

    long long inv(long long x){
        long long r = 1, p = M-2;
        while(p){
            if(p&1) r = r*x % M;
            x = x*x % M;
            p >>= 1;
        }
        return r;
    }

    Fancy() {}

    void append(int val) {
        v.push_back((val - add + M) % M * inv(mul) % M);
    }

    void addAll(int inc) {
        add = (add + inc) % M;
    }

    void multAll(int m) {
        mul = mul * m % M;
        add = add * m % M;
    }

    int getIndex(int i) {
        return i >= v.size() ? -1 : (v[i] * mul + add) % M;
    }
};