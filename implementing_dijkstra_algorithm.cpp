//Time complexity O(ElogV)
//Space Complexity O(V^2)

class Solution{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dis(V, INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,S});
        dis[S] = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(auto it: adj[u]){
                int v = it[0];
                int w = it[1];
                if(dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
            
        }
        return dis;
    }
    
};

//Time complexity O(ElogV)
//Space Complexity O(V^2)
class Solution
{
    class Edge{
        public:
        int distance;
        int vertex;
        Edge(int d, int v){
            distance=d;
            vertex=v;
        }
    };
    
    class Comparator{
        public:
            bool operator()(const Edge& e1, const Edge& e2){
                return e1.distance>e2.distance;
            }
    };
    
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INT_MAX);
        priority_queue<Edge, vector<Edge>, Comparator> pq;
        dist[S]=0;
        pq.push(Edge(dist[S], S));
        while(!pq.empty()){
            Edge e=pq.top();
            pq.pop();
            for(auto edge : adj[e.vertex]){
                int adjNodeDist=edge[1], adjNodeVertex=edge[0];
                int newDistance=e.distance+adjNodeDist;
                if(newDistance<dist[adjNodeVertex]){
                    dist[adjNodeVertex]=newDistance;
                    pq.push(Edge(dist[adjNodeVertex], adjNodeVertex));
                }
            }
        }
        return dist;
    }
};
