#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
void solve(){
int n,q;
cin>>n>>q;
int arr[n][n];
for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        char c;
        cin>>c;
        if(c=='.'){
            arr[i][j] = 0;
        }
        else{
            arr[i][j] = 1;
        }
    }
}
int prefix[n+1][n+1];
for(int i = 1;i<=n;i++){
    for(int j = 0;j<=n;j++){
        prefix[i][j] = arr[i-1][j-1]+prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1];
    }
}
while(q--){
    int y1,x1,y2,x2;
    cin>>y1>>x1>>y2>>x2;
    int num = prefix[y2][x2]-prefix[y1-1][x2]-prefix[y2][x1-1]+prefix[y1-1][x1-1];
    cout<<num<<endl;
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