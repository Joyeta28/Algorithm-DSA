#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll infLL = LLONG_MAX;


int Max = 1e3+123;
vector<ll>dis(Max);

bool bellmanford(int src,int n,int m,vector<vector<int>>&e){
    dis.assign(n,infLL);
    dis[src]=0;
    bool is_cycle = false;
    for(int i=0;i<n-1;i++){
        for(auto &it : e){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dis[u]!=infLL && dis[u]+w < dis[v]){
                dis[v] = dis[u]+w;
            }
        }
    }

    for(auto &it : e){
        int u = it[0];
        int v = it[1];
        int w = it[2];


        if(dis[u]!=infLL && dis[u]+w < dis[v]){
            is_cycle=true;
        }
    }

    return is_cycle;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>e;
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            e.push_back({u,v,w});
        }

       if(bellmanford(0,n,m,e) == true){
        cout<<"has a neg cycle"<<endl;
       }
       else cout<<"does not have a neg cycle"<<endl;
    }
}
