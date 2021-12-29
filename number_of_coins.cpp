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