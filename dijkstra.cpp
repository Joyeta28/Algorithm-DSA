#include <bits/stdc++.h>
using namespace std;

#define infLL 1e9

void dijkstra(vector<vector<pair<int,int>>>&adj,vector<long long>&dis,int n,int src){
    dis[src] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});


    while(!pq.empty()){
        auto curr = pq.top();
        int node = curr.second;
        long long d = curr.first;
        pq.pop();
        if(dis[node]<d) continue;
        for(auto u: adj[node]){
            int v = u.first;
            int w = u.second;

            if(d+w<dis[v]){
                dis[v] = d+w;
                pq.push({dis[v],v});
            }
        }
    }

}

int main() {
    int tc;
    cin>>tc;

    for(int t = 1;t<=tc;t++){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n);
    vector<long long>dis(n,infLL);
    for(int i =0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;//1 based indexing
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cout<<"Case "<<t<<": ";
   dijkstra(adj,dis,n,0);

        if(dis[n-1] == infLL){
            cout<<"Impossible"<<endl;
        }
        else cout<<dis[n-1]<<endl;

    }
    return 0;
}
