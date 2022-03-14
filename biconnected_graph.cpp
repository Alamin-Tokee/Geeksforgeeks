class Solution{
public:
    void addEdge(vector<int>adj[],int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void countAP(vector<int>adj[],vector<int>&dis,vector<int>&low,int u,int t,vector<int>&par,int &r,vector<bool>&vis){
        dis[u] = low[u] = t;
        vis[u] = true;
        t++;
        int children = 0;
        for(int v:adj[u]){
            if(dis[v]==-1){
                children++;
                par[v] = u;
                countAP(adj,dis,low,v,t,par,r,vis);
                low[u] = min(low[u],low[v]);
                if(par[u]==-1 && children > 1) r++;
                if(par[u]!=-1 && low[v]>=dis[u]) r++;
            }else if(v!=par[u]) low[u] = min(low[u],dis[v]);
        }
    }
    //Time complexity O(n+e)
    //Space Complexity O(n)
    int biGraph(int arr[], int n, int e) {
        // code here
        vector<int>adj[n];
        for(int i=0;i<2*e;i+=2){
            addEdge(adj,arr[i],arr[i+1]);
        }
        int r = 0;
        vector<int>par(n,-1);
        vector<int>dis(n,-1);
        vector<int>low(n,-1);
        vector<bool>vis(n,false);
        
        int t = 0;
        countAP(adj,dis,low,0,t,par,r,vis);
        bool connected = true;
        for(int i=0;i<n;i++){
            if(!vis[i]) {connected = false;break;}
        }
        if(r == 0 && connected) return 1;
        else return 0;
    }
};


//Time complexity O(n+e)
 //Space Complexity O(n)
class Solution{
public:
    int biGraph(int arr[],int n,int e){
        if(n<=2) return 1;
        vector<int>degree(n+1,0);
        for(int i=0;i<2*e;i++){
            int u = arr[i], v=arr[i+1];
            degree[u]++;
            degree[v]++;
        }
        for(int i=0;i<n;i++){
            if(degree[i] < 2) return 0;
        }
        return 1;
    }
};