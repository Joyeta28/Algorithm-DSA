class Solution {
    
  public:
    void dfs(int src,int n,vector<vector<int>>& adj,vector<int>&vis,stack<int>&st){
        vis[src]=1;
        for(auto &u: adj[src]){
            if(!vis[u]){
                dfs(u,n,adj,vis,st);
            }
        }
        st.push(src);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        stack<int>st;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,n,adj,vis,st);
            }
        }
        vector<int>v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        
        return v;
    }
};
