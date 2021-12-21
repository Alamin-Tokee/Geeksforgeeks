
//Time Complexity O(n1*n2*n3)
//Space Complexity O(n1*n2*n3)


int solve(string &a, string &b, string &c, int i, int j, int k, vector<vector<vector<int>>> &dp){
    if(i>=a.size() || j>=b.size() || k>=c.size()) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(a[i]==b[j] && b[j]==c[k]){
        return dp[i][j][k]=1+solve(a,b,c,i+1,j+1,k+1,dp);
    }
    return dp[i][j][k]=max({solve(a,b,c,i+1,j,k,dp),solve(a,b,c,i,j+1,k,dp),solve(a,b,c,i,j,k+1,dp)});
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int>>>dp;
    vector<vector<int>>v(n2,vector<int>(n3,-1));
    for(int i=0;i<n1;i++){
        dp.push_back(v);
    }
    return solve(A,B,C,0,0,0,dp);
}

int t[21][21][21];
int solve(string &a, string &b, string &c, int i, int j, int k){
    if(i==0 || j==0 || k==0) return 0;
    if(t[i][j][k]!=-1) return t[i][j][k];
    if(a[i-1]==b[j-1] && b[j-1]==c[k-1]){
        return t[i][j][k]=1+solve(a,b,c,i-1,j-1,k-1);
    }
    return t[i][j][k]=max({solve(a,b,c,i-1,j,k),solve(a,b,c,i,j-1,k),solve(a,b,c,i,j,k-1)});
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    // vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
    memset(t,-1,sizeof(t));
    return solve(A,B,C,n1,n2,n3);
}





int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
     //vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0))); // i start with 1
    // int dp[n1+1][n2+1][n3+1]={}; //i start with 1
    int dp[n1+1][n2+1][n3+1];
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            for(int k=0;k<=n3;k++){
                if(i == 0 || j == 0 || k == 0) dp[i][j][k] = 0;
                
                else{
                    if(A[i-1] == B[j-1] && B[j-1] == C[k-1]){
                        dp[i][j][k]=1+dp[i-1][j-1][k-1];
                    }else{
                        dp[i][j][k]=max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
                    }
                }
            }
        }
    }
    return dp[n1][n2][n3];
}



int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));
    for(int i=n1-1;i>=0;i--){
        for(int j=n2-1;j>=0;j--){
            for(int k=n3-1;k>=0;k--){
                if(A[i]==B[j] && B[j]==C[k]){
                    dp[i][j][k]=1+dp[i+1][j+1][k+1];
                }else{
                    dp[i][j][k]=max({dp[i+1][j][k],dp[i][j+1][k],dp[i][j][k+1]});
                }
            }
        }
    }
    return dp[0][0][0];
}