class Solution{
public:
    int offset[5]={0, 1, 0, -1, 0};
    int bfs(vector<vector<int>>& g,queue<pair<int,int>>&q){
        int flag=0;
        int cnt=0;
        while(!q.empty()){
            int sz=q.size();
            for(;sz--;){
                int u=q.front().first;
                int v=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int x=u+offset[i];
                    int y=v+offset[i+1];
                
                    if(x>=0 and y>=0 and x<g.size() and y<g[0].size() and g[x][y]==1){
                        g[x][y]=2;
                        q.push({x,y});
                        flag=1;
                    }
                }
            }
            if(flag){
                cnt++;
                flag=0;
            }
        }
        return cnt;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        ans+=bfs(grid,q);
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    c++;
                }
            }
        }
        return c ? -1 : ans;
    }
};

class Solution{
public:
    int isSafe(int i,int j,int n,int m){
        if(i>=0 && i<n && j>=0 && j<m){
            return 1;
        }
        return 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<int> dx = {-1,0,0,1};
        vector<int> dy = {0,-1,1,0};
        
        int n = grid.size();
        if(n == 0){
            return -1;
        }
        int m = grid[0].size();
        int fresh = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh += 1;
                }
            }
        }
        int timeTaken = 0;
        while(!q.empty()){
            int q_size = q.size();
            while(q_size > 0){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    if(isSafe(x+dx[k],y+dy[k],n,m) && grid[x+dx[k]][y+dy[k]] == 1){
                        grid[x+dx[k]][y+dy[k]] = 2;//mark as visited
                        fresh -= 1;
                        q.push({x+dx[k],y+dy[k]});//push into queue
                    }
                }
                q_size -= 1;
            }
            timeTaken += 1;
        }
        // no of steps are no of levels-1
        return (fresh>0?-1:timeTaken-1);
    }
};