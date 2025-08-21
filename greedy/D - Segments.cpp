#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
using state = pair<int,int>;
#define endl '\n'

bool comp(const state &a,const state &b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}

void solve(){
    int n;
    cin>>n;
    vector<state> v;
    for(int i = 0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        v.push_back({b,a}); 
    }

    sort(v.begin(),v.end(),comp);

    vector<int> ans;
    int last = -1e9;

    for(int i=0;i<n;i++){
        int r = v[i].first;
        int l = v[i].second;
        if(last < l){ 
            last = r;
            ans.push_back(r);
        }
    }

    cout<<ans.size()<<endl;
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
