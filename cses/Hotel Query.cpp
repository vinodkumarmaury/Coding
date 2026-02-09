#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
void solve(){
int n,m;
cin>>n>>m;
set<pair<int,int>> hotel;
for(int i = 1;i<=n;i++){
    int x;
    cin>>x;
    hotel.insert({x,i});
}



for(int i = 0;i<m;i++){
    int x;
    cin>>x;
    auto it = hotel.lower_bound({x, 0});
    if(it==hotel.end()){
        cout<<0<<" ";
    }
    else{
        int num = it->first;
        int index = it->second;
        num = num-x;
        cout<<index<<" ";
        hotel.erase(it); 
        if(num>0){
        hotel.insert({num,index});
        }
    }
}
cout<<endl;
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