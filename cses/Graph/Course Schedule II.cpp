#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g_rev(n + 1);
    vector<int> indegree(n + 1, 0);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g_rev[b].push_back(a);
        indegree[a]++;
    }

    priority_queue<int> pq;
    vector<int> topo;

    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        int node = pq.top();
        pq.pop();
        topo.push_back(node);

        for(auto &v : g_rev[node]){
            indegree[v]--;
            if(indegree[v] == 0){
                pq.push(v);
            }
        }
    }

    reverse(topo.begin(), topo.end());

    for(int i = 0; i < topo.size(); ++i) {
        cout << topo[i] << (i == topo.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}