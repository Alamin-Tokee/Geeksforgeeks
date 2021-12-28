 //Time complexity O(V+E)
//Space Complexity O(V)
 class Solution{
 public:
	void solve(int node,int parent,int &timer,vector<int> &dis,vector<int> &low,vector<int> &vis,vector<pair<int,int>> &v,vector<int> adj[]){
        vis[node] = 1;
        dis[node] = low[node] = timer++;
        
        for(auto it:adj[node]){
            if(it == parent)
                continue;
            if(!vis[it]){
                solve(it,node,timer,dis,low,vis,v,adj);
                low[node] = min(low[it],low[node]);
                if(dis[node] < low[it]){
                    v.push_back({node,it});
                }
            }else{
                low[node] = min(low[node],dis[it]);
            }
        }
        
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d){
        vector<int> dis(V,INT_MAX);
        vector<int> low(V,INT_MAX);
        vector<int> vis(V,0);
        vector<pair<int,int>> v;
        
        int timer = 0;
        for(int i = 0;i<V;i++) {
    	    if(!vis[i]) {
                solve(i,-1,timer,dis,low,vis,v,adj);
    	    }
	    }
        
        for(auto &it:v){
            if(it.first == c and it.second == d){
                return 1;
            }else if(it.first == d and it.second == c){
                return 1;
            }
        }
        return 0;
    }
};


//Time Complexity O(V+E)
//Space Complexity O(V)
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    bool flag = false;
    int timer;
    void dfs(int u,int parent,vector<int>adj[],vector<int>&vis,vector<int>&low,vector<int>&dis,int c,int d){
        vis[u] = 1;
        static int time=0;
        low[u]=dis[u]=timer++;
        
        for(auto v : adj[u]){
            if(v == parent) continue;
            
            if(!vis[v]){
                dfs(v,u,adj,vis,low,dis,c,d);
                low[u] = min(low[u],low[v]);
                
                if(low[v] > dis[u]){
                    if((u == c && v == d) || (v == c && u == d)) flag = true;
                }
            }else{
                low[u] = min(low[u], dis[v]);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> vis(V,0);
        vector<int> low(V,0);
        vector<int> dis(V,0);
        this->flag=flag;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, -1, adj, vis, low, dis, c, d);
            }
        }
        if(flag) return 1;
        
        return 0;
    }
};

//Example 1
//Time Complexity O(V+E)
//Space Complexity O(V)
    void dfs(vector<int>adj[], int u, vector<int> &vis)
    {
        vis[u] = 1;
        for(int v:adj[u])
        {
            if(!vis[v])
                dfs(adj,v,vis);
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
        adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());
        vector<int> vis(V,0);
        dfs(adj,c,vis);
        return !vis[d];
    }

//Example 2
//Time Complexity O(V+E)
//Space Complexity O(V)
    void DFS_ExcludeEdge(int v, vector<int> adj[], vector<int> &visited,int c, int d,vector<int>&freq)
	{
	    visited[v]=1;
	    freq[v]=0;
	    for(int i=0;i<adj[v].size();i++)
	    {
	        if(!visited[adj[v][i]])
	        {
	            if((v==c && adj[v][i]==d) || (v==d && adj[v][i]==c))
	             continue;
	            
	            DFS_ExcludeEdge(adj[v][i],adj,visited,c,d,freq); 
	        }
	    }
	}
	
	void DFS(int v, vector<int>adj[], vector<int> &visited,vector<int> &freq)
	{
	    visited[v]=1;
	    freq[v]=1;
	    for(int i=0;i<adj[v].size();i++)
	    {
	        if(!visited[adj[v][i]])
	            DFS(adj[v][i],adj,visited,freq);
	    }
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> visited(V);
        vector<int> freq(V,-1);
        DFS(c,adj,visited,freq);
        visited.clear();
        visited.resize(V);
        DFS_ExcludeEdge(c,adj,visited,c,d,freq);
        
        for(int i=0;i<V;i++)
        {
            if(freq[i]==1)
             return 1;
        }
        return 0;
        
    }
    
    
//Example 3
//Time Complexity O(V+E)
//Space Complexity O(V)
    void dfs(int src,vector<bool>&visited,vector<int> adj_list[],int c,int d)
	{
		visited[src] = true;
		for(auto i:adj_list[src])
		{
		    if((src==c && i==d)||(src==d && i==c))
		        continue;
		    if(!visited[i])
		        dfs(i,visited,adj_list,c,d);
		}
		
	}
	
   int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool>visited(V,false);
        dfs(c,visited,adj,c,d);
        
        if(!visited[d])
            return 1;
        return 0;
    }
