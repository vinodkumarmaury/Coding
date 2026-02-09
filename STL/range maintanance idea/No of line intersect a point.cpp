// We are given N ranges varies from Li to Ri on number line. Then you are given Q queries in form of ? Y, which means you have to return how many ranges passes through this points. Constraints N, Q <=1e5 Li, Ri, Y <=1e9




#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
void solve(){
int n,q;
cin>>n>>q;
vector<int> arr,brr;
for(int i = 0;i<n;i++){
    int x,y;
    cin>>x>>y;
    arr.push_back(x);
    brr.push_back(y);
}
sort(arr.begin(),arr.end());
sort(brr.begin(),brr.end());



// Idea we will count how many don't interset if  point>y or point<x
while(q--){
    int point;
    cin>>point;
int num1 = lower_bound(brr.begin(),brr.end(),point)-brr.begin();
int num2 = n-(upper_bound(arr.begin(),arr.end(),point)-arr.begin());
cout<<(n-num1-num2)<<endl;
}
}



signed main(){
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