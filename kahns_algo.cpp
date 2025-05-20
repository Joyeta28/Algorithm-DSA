#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>>adj;


int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>indegree(n+1);
    vector<int>ans;
    queue<int>q;
    adj.resize(n+1);
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) {
        q.push(i);
        ans.push_back(i);
        }
    }
    
    while(!q.empty()){
        int u=q.front();
        
        q.pop();
        for(auto v:adj[u]){
            indegree[v]--;
            if(indegree[v]==0) {
                q.push(v);
                ans.push_back(v);
            }    
        }
    }
    if(ans.size()!=n) cout<<"has a cycle"<<endl;
    else{
        for(auto u:ans){
            cout<<u<<" ";
        }
        cout<<endl;
    }
    
}
    
