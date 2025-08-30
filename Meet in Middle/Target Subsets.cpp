// Description
// You are given an array of length 
// N
// N, and a number 
// X
// X. Find the number of subsets with the sum of elements less than equal to 
// X
// X. Note: The sum of elements in an empty subset is 
// 0
// 0. The set may contain duplicate elements.

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

vector<ll> generateAllSubset(vector<int> num){
    vector<ll> ans;
    
    int sz = num.size();

    for(ll mask = 0;mask<(1<<sz);mask++){
        ll sum = 0;
        for(int i = 0;i<sz;i++){
            if(mask&(1<<i))sum+=num[i];
        }
        ans.push_back(sum);
    }
    return ans;
}

void solve(){
int n,x;
cin>>n>>x;
vector<int> arr(n);
for(int i = 0;i<n;i++){
    cin>>arr[i];
}

vector<int> left(arr.begin(),arr.begin()+n/2);
vector<int> right(arr.begin()+n/2,arr.end());

vector<ll> leftSubset = generateAllSubset(left);
vector<ll> rightSubset = generateAllSubset(right);

sort(leftSubset.begin(),leftSubset.end());

ll count = 0;

for(ll i = 0;i<rightSubset.size();i++){
    ll rem = x-rightSubset[i];
    ll index = upper_bound(leftSubset.begin(),leftSubset.end(),rem)-leftSubset.begin();
    count+=index;
}

cout<<count<<endl;

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