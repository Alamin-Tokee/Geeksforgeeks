
//Time complexity O(|S|)
//Space complexity O(|S|)
class Solution{   
public:
    int lcs(string x,string y){
        int m = x.size(), n = y.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int findMinInsertions(string S){
        // code here 
        string s1 = S;
        reverse(s1.begin(),s1.end());
        return S.size() - lcs(S,s1);
    }
};



class Solution{   
public:
    int dp[501][501];
    int lcs(string x,string y,int m,int n){
        if(m == 0 || n == 0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(x[m-1] == y[n-1]) return dp[m][n] = 1 + lcs(x, y, m-1, n-1);
        return dp[m][n] = max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
    }
    int findMinInsertions(string S){
        // code here 
        memset(dp, -1, sizeof(dp));
        string s1 = S;
        reverse(s1.begin(),s1.end());
        return S.size() - lcs(S,s1,S.length(),S.length());
    }
};


class Solution{
public:
    int dp[501][501];
    int find(int l, int r, string s){
    
        if(l > r){
            return 0;
        }
        
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        
        if(s[l] == s[r]){
            return dp[l][r] = find(l+1, r-1, s);
        }
        else{
            return dp[l][r] = 1 + min(find(l+1, r, s), find(l, r-1, s));
        }
        
    }
    
    
    int findMinInsertions(string S){
            
       // dp[S.length()][S.length()];   
        memset(dp, -1, sizeof(dp));
        
        return find(0, S.length()-1, S);    
    }
};