// Description
// Given an array of size 
// N
// N, and 
// Q
// Q queries, for each query, you need to get the indices of the elements of the array whose subset-sum is equal to the queried sum 
// s
// u
// m
// i
// sum 
// i
// ​
//  , if possible, else return 
// −
// 1
// −1.

// Complete the Function subset_queries( vector<int> &arr, vector<int> &queries ) that takes vector arr and vector queries as input.

// Input Format
// The first line of input contains two integers - 
// N
// N, 
// Q
// Q where 
// N
// N is the size of the array and 
// Q
// Q is a number of queries.
// The second line of input contains 
// N
// N space-separated integers, which are array elements.
// The third line of input contains 
// Q
// Q space-separated integers, which are queries.

// Output Format
// Return a vector < vector < int > > having 
// 0
// 0-based indices of the elements of the array whose subset-sum is equal to the queried sum 
// s
// u
// m
// i
// sum 
// i
// ​
//   for each 
// i
// t
// h
// i 
// th
//   query, if possible, else return vector { 
// −
// 1
// −1 }.
// If the returned vector < vector < int > > from the function subset_queries( vector<int> &arr, vector<int> &queries ) is valid, then the program prints 
// 1
// 1. Otherwise, prints 
// −
// 1
// −1.

// Constraints
// 1
// ≤
// N
// ≤
// 100
// 1≤N≤100 , size of arr
// 1
// ≤
// Q
// ≤
// 1
// 0
// 5
// 1≤Q≤10 
// 5
//   , size of queries
// 1
// ≤
// a
// r
// r
// [
// i
// ]
// ≤
// 1
// 0
// 5
// 1≤arr[i]≤10 
// 5
 
// 1
// ≤
// s
// u
// m
// i
// ≤
// 1
// 0
// 5
// 1≤sum 
// i
// ​
//  ≤10 
// 5
 

// Sample Input 1
// 5 3
// 1 2 3 4 5
// 7 16 3
// Sample Output 1
// 1
// -1
// 1
// Note
// For the first query 
// 7
// 7, there exists a subset of 
// a
// r
// r
// arr that sums to 
// 7
// 7 (for example 
// 2
// +
// 5
// 2+5), so the checker prints 
// 1
// 1. For the second query 
// 16
// 16, no subset sums to 
// 16
// 16, so the function should return 
// {
// −
// 1
// }
// {−1} and the program prints 
// −
// 1
// −1. For the third query 
// 3
// 3, a subset exists (for example 
// 3
// 3), so the checker prints 
// 1
// 1.


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t

vector<vector<int>> dp;

int rec(int level,int sumLeft,vector<int> &arr,int n){
    if(level==n){
        if(sumLeft==0)return 1;
        return 0;
    }
    if(dp[level][sumLeft]!=-1){
        return dp[level][sumLeft];
    }

    int ans  = rec(level+1,sumLeft,arr,n);
    if(sumLeft-arr[level]>=0){
        ans = ans | rec(level+1,sumLeft-arr[level],arr,n);
    }
    return dp[level][sumLeft] = ans;
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    int n = arr.size();
    vector<vector<int>> ans;
    int maxQ = *max_element(queries.begin(), queries.end());
    
    dp.resize(n+1,vector<int>(maxQ+1,-1));
     
    for (int s = 0; s <= maxQ; s++) {
        rec(0, s, arr, n);
    }

    for (auto sum : queries) {
        int ok = rec(0, sum, arr, n);
        if (ok) {
            vector<int> temp;
            int level = 0;
            while (level < n && sum > 0) {
                if (sum - arr[level] >= 0 && rec(level+1, sum - arr[level], arr, n)) {
                    temp.push_back(level);
                    sum -= arr[level];
                    level++;
                } else if (rec(level+1, sum, arr,n)) {
                    level++;
                } else {
                    break;  
                }
            }
            ans.push_back(temp);
        } else {
            ans.push_back({-1});
        }
    }
    return ans;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++) cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { 
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        } else cout << 101 << endl;
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
