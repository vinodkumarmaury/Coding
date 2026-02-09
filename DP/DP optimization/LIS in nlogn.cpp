#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'


void solve(){
int n;
cin>>n;
vector<int> arr(n);
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
vector<int> lis;
int insertAt[n];
for(int i = 0;i<n;i++){
     if(lis.empty()||lis.back()<arr[i]){
          lis.push_back(arr[i]);
          insertAt[i] = lis.size();
     }
     else{
          auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
          *it = arr[i];
          insertAt[i] = it-lis.begin()+1;
     }
     cout<<i<<" th interation, how lis is forming : ";
     for(auto &x:lis){
          cout<<x<<" ";
     }
     cout<<endl;
}
cout<<"index at which value are inserted : ";
for(auto &x:insertAt){
     cout<<x<<" ";
}
cout<<endl;
cout<<"length of LIS : "<<lis.size()<<endl;
cout<<"printing LIS : ";
vector<int> final_lis;
int currLen = lis.size();
for(int i = n-1;i>=0;i--){
     if(insertAt[i]==currLen){
          final_lis.push_back(arr[i]);
          currLen--;
     }
}
reverse(final_lis.begin(),final_lis.end());
for(auto &x:final_lis){
     cout<<x<<" ";
}
cout<<endl;
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