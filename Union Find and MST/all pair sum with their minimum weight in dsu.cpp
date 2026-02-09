#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind{
         vector<ll> par,rank;
         ll set_size; // #ofcc
         ll n;
         UnionFind(ll a){ // initialization
            set_size=n=a;
            par.resize(n+1);
            rank.assign(n+1,1);
            for(ll i=1; i<=n; i++)par[i]=i;
         }
         ll find(ll x){
               if(par[x]==x)return x;
               else return par[x]=find(par[x]);
         }
         void merge(ll x, ll y){
              x=find(x);
              y=find(y);
              if(x==y)return;
              if(rank[x]<rank[y]){
                   rank[y]+=rank[x];
                   par[x]=y;
              }
              else{
                rank[x]+=rank[y];
                par[y]=x;
              }
              set_size--;
         }
         void reset(){
            for(ll i=1; i<=n; i++)par[i]=i;
            rank.assign(n+1,1);
            set_size=n;
         }

        ll size(){
            return set_size;
        }
        void print(){
            for(ll i = 1;i<=n;i++){
                cout<<i<<"->"<<par[i]<<endl;
            }
        }
        ll comp_size(ll x){
        return rank[find(x)];
        }
};


void solve(){
    ll n;
    cin>>n;
    UnionFind uf(n);
    vector<pair<ll,pair<ll,ll>>> g;
    g.resize(n+1);
    for(ll i = 0;i<n-1;i++){
        ll a,b,w;
        cin>>a>>b>>w;
        g.push_back({w,{a,b}});
    }
    sort(g.rbegin(),g.rend());
   long long ans = 0;

    for(auto &edge : g){
        ll w = edge.first;
        ll a = edge.second.first;
        ll b = edge.second.second;
        ll pa = uf.find(a);
        ll pb = uf.find(b);
        if(pa != pb){
            long long szA = uf.comp_size(pa);
            long long szB = uf.comp_size(pb);
            ans += 1LL * w * szA * szB; // contribution
            uf.merge(pa, pb);
        }
    }

    cout << ans << "\n";
}


int main(){
    ll t;
    cin>>t;
    while(t--){
     solve();
    }

}



