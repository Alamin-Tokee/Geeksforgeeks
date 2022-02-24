//Time Complexity O(M*N)
//Space Complexity O(M*N)
class Solution{
public:
    vector<vector<int>>visited;
    int helper(vector<vector<char>>&mat,int m,int n,int i,int j){
        if(i<0 or j<0 or i>=m or j>=n or mat[i][j]=='W' or visited[i][j]==1){
            return 1e9+1;
        }
        if(mat[i][j]=='B') return 0;
        visited[i][j] = 1;
        int u = 1+helper(mat,m,n,i-1,j);
        int r = 1+helper(mat,m,n,i,j+1);
        int d = 1+helper(mat,m,n,i+1,j);
        int l = 1+helper(mat,m,n,i,j-1);
        visited[i][j] = 0;
        
        return min(u, min(r, min(d, l)));
    }
    vector<vector<int> > findDistance(vector<vector<char> >& mat, int M, int N) { 
        vector<vector<int>>res(M,vector<int>(N,0));
        visited.resize(M,vector<int>(N,0));
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(mat[i][j]=='O'){
                    res[i][j] = helper(mat,M,N,i,j) >= 1e6 ? -1 : helper(mat,M,N,i,j);
                }else if(mat[i][j]=='W'){
                    res[i][j] = -1;
                }else{
                    res[i][j] = 0;
                }
            }
        }
        return res;
    }
};

//Time Complexity O(M*N)
//Space Complexity O(M*N)
class Solution{
public:
  void dfs(vector<vector<char>>&mat,vector<vector<int>>&ans,int r,int c,int d){
      if(r < 0 || c < 0 || r >= mat.size() || c >= mat[0].size() || mat[r][c]=='W' || mat[r][c]=='B' || d > ans[r][c]) return;
       
      ans[r][c] = d;
     
      dfs(mat,ans,r+1,c,d+1);
      dfs(mat,ans,r,c+1,d+1);
      dfs(mat,ans,r-1,c,d+1);
      dfs(mat,ans,r,c-1,d+1);
  }
  vector<vector<int> > findDistance(vector<vector<char> >& mat, int M, int N){
      vector<vector<int>>ans(M,vector<int>(N,0));
      for(int i=0;i<M;i++){
          for(int j=0;j<N;j++){
               
              if(mat[i][j]=='W') ans[i][j] = -1;
              if(mat[i][j]=='B') dfs(mat,ans,i,j,0);
          }
      }
      return ans;
  }
};

//Time Complexity O(M*N)
//Space Complexity O(M*N)
class Solution{
public:
  vector<pair<int,int>> p={{1,0},{-1,0},{0,1},{0,-1}};
  int bfs(vector<vector<char>> v,int i,int j,int M,int N)
  {
      queue<pair<int,int>> q;
      vector<vector<int>> vis(M,vector<int> (N,0));
      q.push({i,j});
      vis[i][j]++;
      int level=0;
      while(!q.empty())
      {
          level++;
          int n=q.size();
          for(int i=0;i<n;i++)
          {
              auto b=q.front();
              for(auto k:p)
              {
                  int x=b.first+k.first;
                  int y=b.second+k.second;
                  if(x<0 or y<0 or x==M or y==N or v[x][y]=='W') continue;
                  if(v[x][y]=='B') return level;
                  if(!vis[x][y]){
                      vis[x][y]++;
                      q.push({x,y});
                  }
              }
              q.pop();
          }
      }
      return -1;
  }
  vector<vector<int> > findDistance(vector<vector<char> >& mat, int M, int N) 
  { 
      // Your code goes here
      vector<vector<int>> ans(M,vector<int> (N,0));
      for(int i=0;i<M;i++){
          for(int j=0;j<N;j++){
              if(mat[i][j]=='W') ans[i][j]=-1;
              if(mat[i][j]=='O') ans[i][j]=bfs(mat,i,j,M,N);
          }
      }
      return ans;
  } 
};