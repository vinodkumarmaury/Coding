#include<bits/stdc++.h>
using namespace std;
#define F first 
#define S second

struct weighted_dsu{
vector<int> par,rank,wt;
int n,set_size;
weighted_dsu(int a){
    set_size = n = a;
    par.resize(n+1);
    for(int i = 1;i<=n;i++)par[i] = i;
    rank.assign(n+1,0);
    wt.assign(n+1,0);
}

pair<int,int> find(int x){
    if(par[x]==x)return {x,0};
    auto temp = find(par[x]);
    // path compression
    par[x] = temp.F;
    wt[x] = (temp.S+wt[x])%3;
    return {par[x],wt[x]};
}

int get_relation(int x,int y){
    auto xpath = find(x);
    auto ypath = find(y);
    if(xpath.F!=ypath.F){
        assert(1==0);
    }
    else{
        return xpath.S-ypath.S;
    }
}

bool add_info(int x,int y,int c){
    auto xpath = find(x);
    auto ypath = find(y);
    if(xpath.F==ypath.F)return false;
    if(rank[xpath.F]>=rank[ypath.F]){
        par[ypath.F] = xpath.F;
        wt[ypath.F] = (xpath.S-ypath.S-c+3)%3;
        if(rank[xpath.F]==rank[ypath.F])rank[xpath.F]++;
    }
    else{
        par[xpath.F] = ypath.F;
        wt[xpath.F] = (c+ypath.S-xpath.S+3)%3;
    }
    return true;
}

};


void solve(){
    int n,k;
    cin>>n>>k;
   weighted_dsu chain(n);
    int ans = 0;
    while(k--){
            int type,x,y;
            cin>>type>>x>>y;
            int c = 0;
            if(type==2)c = 1;
            if(x>n||y>n||x<=0||y<=0){
                ans++;
                continue;
            }
           if(chain.add_info(x,y,c)){

           }
           else{
            int currVal = chain.get_relation(x,y);
            if((currVal-c+3)%3!=0)ans++;
           }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}




