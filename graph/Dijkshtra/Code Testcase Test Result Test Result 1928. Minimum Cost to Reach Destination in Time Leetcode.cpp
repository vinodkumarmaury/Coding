#include<bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
using state = pair<long long,long long>;
using ll  = long long;
#define F first
#define S second


class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<long long> bestTime(n+1,inf);
        vector<vector<state>> adj(n+1);
        for(int i = 0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            adj[a].push_back({c,b});
            adj[b].push_back({c,a});
        }
        // edges =>{source,destination,fees};
        priority_queue<pair<int,state>> pq;
        pq.push({-passingFees[0],{0,0}});
        bestTime[0] = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int fees = -curr.F;
            int node = curr.S.F;
            int time = curr.S.S;
            if(node==n-1)return fees;

            for(auto &x:adj[node]){
               int t = x.F;
               int v = x.S;
               int newTime = t+time;
               int newFees = fees+passingFees[v];
               if(newTime<=maxTime&&newTime<bestTime[v]){
                bestTime[v] = newTime;
                pq.push({-newFees,{v,newTime}});
               }
            }
        }
        return -1;
    }
};
