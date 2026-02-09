#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'


struct hashing{
    int p;
    int n;
    int mod;
    string s;
    vector<ll> forward_hash;
    vector<ll> reversed_hash;
    vector<ll> power;

    void init(string ss, int _p,int _mod){
     s = ss;
     n = s.length();
     mod = _mod;
     p = _p;
     forward_hash.assign(n+1,0);
     reversed_hash.assign(n+1,0);
     power.assign(n+1,0);
     forward_hash[0] = s[0]-'a'+1;
     reversed_hash[n-1] = s[n-1]-'a'+1;
     power[0] = 1;
     for(int i = 1;i<n;i++){
     forward_hash[i] = (forward_hash[i-1]*p+s[i]-'a'+1)%mod;
     power[i] = (power[i-1]*p)%mod;
     reversed_hash[n-i-1] = (reversed_hash[n-i]*p+s[n-1-i]-'a'+1)%mod;
     }
    }
    
    ll getRangeForward_hash(ll l, ll r){
        if(l>r)return 0;
        if(l==0)return forward_hash[r];
        ll x = forward_hash[r]-forward_hash[l-1]*power[r-l+1];
        x = (x+mod)%mod;
        return x;
    }

    ll getRangeReverse_hash(ll l, ll r){
        if(l>r)return 0;
        if(r==n-1)return reversed_hash[l];
        ll x = reversed_hash[l]-reversed_hash[r-1]*power[r-l+1];
        x = (x+mod)%mod;
        return x;
    }
};


struct DoubleHashing{
hashing h1,h2;

void init(const string &s, ll b1 = 31, ll m1 = 999999937, ll b2 = 37, ll m2 = 999999929) {
    h1.init(s, b1, m1);
    h2.init(s, b2, m2);
  }
   pair<ll, ll> get_forward_hash_check(ll l, ll r){
    return {h1.getRangeForward_hash(l, r), h2.getRangeForward_hash(l, r)};
  }


  pair<ll, ll> get_reverse_hash_check(ll l, ll r){
    return {h1.getRangeReverse_hash(l, r), h2.getRangeReverse_hash(l, r)};
  }
};


void solve(){
string s1,s2;
cin>>s1>>s2;

hashing h1,h2;
h1.init(s1,23,9999937);
h2.init(s2,23,9999937);
int n = s1.length();
int m = s2.length();
if(h1.forward_hash[n-1]==h2.forward_hash[m-1]){
    cout<<"String are  Equal"<<endl;
    if(h1.reversed_hash[0]==h1.forward_hash[n-1]){
        cout<<"string is palindrome"<<endl;
    }
}
else{
    cout<<"Not equal"<<endl;
    if(h1.reversed_hash[0]==h1.forward_hash[n-1]){
        cout<<"string 1 is palindrome"<<endl;
    }
    if(h2.reversed_hash[0]==h2.forward_hash[n-1]){
        cout<<"string 2 is palindrome"<<endl;
    }
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