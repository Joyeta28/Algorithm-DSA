class Solution {
    void dfs(int src,vector<vector<int>> &adj,vector<int>&vis,stack<int>&st){
        vis[src] = 1;
        for(auto u:adj[src]){
            if(!vis[u]){
                dfs(u,adj,vis,st);
            }
        }
        st.push(src);
    }
    
    void dfsTrav(int src,vector<vector<int>>&radj,vector<int>&vis){
        vis[src]=1;
        for(auto u:radj[src]){
            if(!vis[u]){
                dfsTrav(u,radj,vis);
            }
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int n = adj.size();
        stack<int>st;
        vector<int>vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        fill(vis.begin(),vis.end(),0);
        vector<vector<int>>radj(n);
        for(int i=0;i<n;i++){
            for(auto u:adj[i]){
                radj[u].push_back(i);
            }
        }
        
        int count = 0;
        while(!st.empty()){
            
            int u = st.top();
            if(!vis[u]){
                dfsTrav(u,radj,vis);
                count++;
            }
            st.pop();
        }
        return count;
    }
};
