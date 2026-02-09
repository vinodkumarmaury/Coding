#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

const ll inf = 1e18;

void solve(){
int n,m,q;
cin>>n>>m>>q;
vector<vector<ll>> dist(n+1,vector<ll>(n+1,inf));
for(int i = 0;i<=n;i++){
    dist[i][i] = 0;
}
for(int i = 0;i<m;i++){
    ll a,b,c;
    cin>>a>>b>>c;
    dist[a][b] = min(c,dist[a][b]);
    dist[b][a] = min(c,dist[b][a]);
}
for(int k = 1;k<=n;k++){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
}
while(q--){
    int a,b;
    cin>>a>>b;
    if(dist[a][b]==inf){
        cout<<-1<<endl;
    }
    else{
        cout<<dist[a][b]<<endl;
    }
}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}