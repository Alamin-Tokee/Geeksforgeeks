//Time Complexty O(v!)
//Space Complexity O(v)

class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    void dfs(int v,vector<int>adj[],int src,int des,int &c){
        if(src==des){
            c++;
            return;
        }
        for(auto& val:adj[src]){
            dfs(v,adj,val,des,c);
        }
    }
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        int c=0;
        dfs(V,adj,source,destination,c);
        return c;
    }
};

//Time Complexty O(v!)
//Space Complexity O(v)
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int dfs(int v,vector<int>adj[],int src,int des){
        if(src==des) return 1;
        
        int c=0;
        for(int i=0;i<adj[src].size();i++){
            c+=dfs(v,adj,adj[src][i],des);
        }
        
        return c;
    }
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here

        return dfs(V,adj,source,destination);
    }
};

//Time Complexty O(v!)
//Space Complexity O(v)
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        queue<int>q;
        q.push(source);
        int count = 0;
        while(!q.empty()){
            int curNode=q.front();
            q.pop();
            if(curNode==destination) count++;
            
            for(int neighbor:adj[curNode]){
                q.push(neighbor);
            }
        }
        return count;
    }
};