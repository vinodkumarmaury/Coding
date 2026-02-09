#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
void solve(){
int n;
cin>>n;
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
stack<int> st;
int nge[n];
for(int i = n-1;i>=0;i--){
    while(!st.empty()&&arr[st.top()]<=arr[i]){
        st.pop();
    }
    if(!st.empty()){
        nge[i] = st.top();
    }
    else{
        nge[i] = -1;
    }
    st.push(i);
}
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