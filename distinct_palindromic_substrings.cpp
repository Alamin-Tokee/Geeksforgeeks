  class Solution{
  public:
    int palindromeSubStrs(string s) {
        // code here
        int n = s.size();
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        for(int gap = 1; gap <= n; gap++){
            for(int i = 0, j = i + gap - 1; j < n ; i++, j++){
                if(gap == 1) dp[i][j] = true;
                else if(gap == 2) dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
            }
        }
        unordered_set<string>st;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dp[i][j]) st.insert(s.substr(i, (j-i+1)));
            }
        }
        return st.size();
    }
};