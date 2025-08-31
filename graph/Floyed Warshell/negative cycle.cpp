#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
const int inf = 1e9;

void solve(){
int n,m;
cin>>n>>m;
vector<vector<int>> dist(n+1,vector<int>(n+1,inf));

for(int j = 0;j<m;j++){
    int a,b,c;
    cin>>a>>b>>c; 
    dist[a][b] = min(c,dist[a][b]); //assuming directed
}

// for(int i = 0;i<=n;i++){
//     dist[i][i] = 0;
// }

for(int k = 1;k<=n;k++){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
}

int ans = inf;
for(int i = 1;i<=n;i++){
    ans = min(ans,dist[i][i]);  
}

if(ans<0) cout<<"Negative Cycle"<<endl;
else cout<<"No"<<endl;
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