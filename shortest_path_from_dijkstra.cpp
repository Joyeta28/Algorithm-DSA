 vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>parent(n+1,-1);
        
        vector<int>dis(n+1,INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dis[1] = 0;
        pq.push({0,1});
      
        while(!pq.empty()){
            auto curr = pq.top();
            int node = curr.second;
            int d    = curr.first;
            pq.pop();
            if(d>dis[node]) continue;
         
            for(auto it:adj[node]){
                int u = it.first;
                int w = it.second;
                
                if(d+w<dis[u]){
                    dis[u] = d+w;
                    pq.push({d+w,u});
                    parent[u] = node;
                }
            }
        }
        if(dis[n] == INT_MAX) return {-1};
       
        vector<int>path;
       
          
        for (int cur = n; cur != -1; cur = parent[cur]) {
            path.push_back(cur);
        }
       
        reverse(path.begin(),path.end());
         path.insert(path.begin(), dis[n]);
    
        return path;
    }

//https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
