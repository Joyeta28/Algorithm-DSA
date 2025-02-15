public:
    void dfs(int src, vector<int>adj[],vector<bool>&vis){
        vis[src] = true;
        for(auto u:adj[src]){
            if(!vis[u]){
                dfs(u,adj,vis);
            }
        }
    }
    
    bool is_connected(vector<int>adj[], int V){
       int non_zero_degreenode;
       
       for(int i = 0; i<V; i++){
           if(adj[i].size() != 0){
               non_zero_degreenode = i;
               break;
           }
       }
    
    vector<bool>vis(V,false);
    dfs(non_zero_degreenode,adj,vis);
    
    for(int i = 0;i<V;i++){
        if(!vis[i] && adj[i].size()!=0){
            return false;
        }
    }
    return true;
    }
    
	int isEulerCircuit(int V, vector<int>adj[]){
	    if(is_connected(adj,V) == false){
	        return 0;
	    }
	    
	    int odd_degree_count = 0;
	for(int i = 0; i<V; i++){
	    if(adj[i].size()%2 != 0){
	        odd_degree_count++;
	    }
	}
	if(odd_degree_count == 2){//euler path
	    return 1;
	}
	else if(odd_degree_count > 2){
	    return 0;
	}
	if(odd_degree_count == 0){//euler circuit
	    return 2;
	}
	}
	
};
