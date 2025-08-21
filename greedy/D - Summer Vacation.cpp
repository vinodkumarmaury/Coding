#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
void solve(){
int n,m;
cin>>n>>m;
vector<pair<int,int>> v(n);
vector<vector<int>> ans(m);
for(int i = 0;i<n;i++){
cin>>v[i].first>>v[i].second;
if(v[i].first>m)continue;
ans[m-v[i].first].push_back(v[i].second);
}
multiset<int> mt;
ll res = 0;
for(int i = m-1;i>=0;i--){
    for(auto &x:ans[i]){
        mt.insert(x);
    }
    if(mt.size()>0){
        res+=*mt.rbegin();
        mt.erase(prev(mt.end()));
    }
}
cout<<res<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}