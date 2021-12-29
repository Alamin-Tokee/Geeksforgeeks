
//Time Complexity O(V*M)
//Space Complexity O(V*M)

class Solution{
	public:
	int solve(int coins[],int w,int n,vector<vector<int>>&memo){
	    if(n == 0 || w == 0) return w == 0 ? 0 : INT_MAX-1;
	    if(memo[w][n]!=-1) return memo[w][n];
	    if(coins[n-1] > w) return memo[w][n] = 0 + solve(coins,w,n-1,memo);
	    return memo[w][n]=min(0+solve(coins,w,n-1,memo),1+solve(coins,w-coins[n-1],n,memo));
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>memo(V+1,vector<int>(M+1,-1));
	    int mCoin = solve(coins,V,M,memo);
	    
	    return mCoin == INT_MAX - 1 ? -1 : mCoin;
	} 
	  
};


//Time Complexity O(V*M)
//Space Complexity O(V*M)

class Solution{
	public:
	const int inf = 1e9;
	int minCoins(int coins[], int M, int V) 
	{ 
	   vector<vector<int>>dp(M+1,vector<int>(V+1));
	   for(int i=0;i<=M;i++){
	       for(int j=0;j<=V;j++){
	           if(j == 0) dp[i][j] = 0;
	           else if(i == 0) dp[i][j] = inf;
	           else{
	               if(coins[i-1] <= j){
	                   dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
	               }else{
	                   dp[i][j] = dp[i-1][j];
	               }
	           }
	       }
	   }
	   return dp[M][V] == inf ? -1 : dp[M][V];
	} 
};


//Time Complexity O(V*M)
//Space Complexity O(V*M)

class Solution{
    public:
    const int inf = 1e9;
	int minCoins(int coins[], int M, int V) { 
	    vector<vector<int> > dp(V+1,vector<int>(M+1));
	    for(int i=0; i<=V; i++){
	        for(int j=0; j<=M; j++){
	            if(i == 0){
	                dp[i][j] = 0;
	            }
	            else if(j == 0){
	                dp[i][j] = inf;
	            }
	            else{
	                if(i>=coins[j-1]){
	                    dp[i][j] = min(dp[i][j-1],1+dp[i-coins[j-1]][j]);
	                }
	                else{
	                    // move on to next
	                    dp[i][j] = dp[i][j-1];
	                }
	            }
	        }
	    }
	    return (dp[V][M]==inf?-1:dp[V][M]);
	} 
};


//Time Complexity O(V*M)
//Space Complexity O(V)
class Solution{
    public:
    const int inf = 1e9;
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<int> dp(V+1,inf);//intially say all are impossible
	    dp[0] = 0;
        for(int i=1; i<=V; i++){
            for(int j=0; j<M; j++){
	            if(i>=coins[j]){
	                dp[i] = min(dp[i],1+dp[i-coins[j]]);
	            }
            }
        }
	    
	    return (dp[V]==inf?-1:dp[V]);
	}
};
