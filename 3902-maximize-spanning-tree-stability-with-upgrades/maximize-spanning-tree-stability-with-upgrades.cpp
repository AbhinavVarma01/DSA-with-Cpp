class Solution {
public:

vector<int> parent;

int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

bool unite(int a,int b){
    a=find(a); 
    b=find(b);
    if(a==b) return false;
    parent[b]=a;
    return true;
}

bool ok(int n, vector<vector<int>>& e, int k, int x){
    iota(parent.begin(), parent.end(), 0);
    int used=0, up=0;

    for(auto &v:e)
        if(v[3] && (v[2]<x || !unite(v[0],v[1]))) return 0;
        else if(v[3]) used++;

    for(auto &v:e)
        if(!v[3] && v[2]>=x && unite(v[0],v[1])) used++;

    for(auto &v:e)
        if(!v[3] && v[2]<x && 2*v[2]>=x && up<k && unite(v[0],v[1]))
            up++, used++;

    return used==n-1;
}

int maxStability(int n, vector<vector<int>>& e, int k) {
    parent.resize(n);
    int l=1, r=200000, ans=-1;
    while(l<=r){
        int m=(l+r)/2;
        if(ok(n,e,k,m)) ans=m, l=m+1;
        else r=m-1;
    }
    return ans;
}
};