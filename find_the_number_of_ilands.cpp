 //TC O(n*m)
//SC O(1)

 class Solution{
 public:
    void dfs(vector<vector<char>>& g,int row,int col){
        if(row < 0 || col < 0 || row >= g.size() || col >= g[0].size() || g[row][col]!='1') return;
        
        g[row][col] = '0';
        
        //Here is the up down left right cases
        dfs(g,row+1,col);
        dfs(g,row,col+1);
        dfs(g,row-1,col);
        dfs(g,row,col-1);
        
        //Here is the diaginal cases
        dfs(g,row+1,col+1);
        dfs(g,row-1,col-1);
        dfs(g,row+1,col-1);
        dfs(g,row-1,col+1);
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int cnt = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};