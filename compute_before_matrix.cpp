//TC O(n*m)
//SC O(n*m)

class Solution{
    public:
    vector<vector<int>> computeBeforeMatrix(int N, int M, vector<vector<int>> after){
        // Code here
        vector<vector<int>> res(N,vector<int>(M,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(i == 0 && j == 0){
                    res[i][j] = after[i][j];
                }else if(i==0 && j>0){
                    res[i][j] = after[i][j] - after[i][j-1];
                }else if(i>0 && j==0){
                    res[i][j] = after[i][j] - after[i-1][j];
                }else{
                    res[i][j] = after[i][j] - (after[i][j-1]+after[i-1][j]) + after[i-1][j-1];
                }
            }
        }
        return res;
    }
};

//TC O(n*m)
//SC O(1)
class Solution{
    public:
    vector<vector<int>> computeBeforeMatrix(int N, int M, vector<vector<int>> after){
        // Code here
        for(int i=0;i<N;i++){
            for(int j=M-1;j>=1;j--){
                after[i][j] = after[i][j]-after[i][j-1];
            }
        }
        
        for(int j=0;j<M;j++){
            for(int i=N-1;i>=1;i--){
                after[i][j]=after[i][j]-after[i-1][j];
            }
        }
        return after;
    }
};

//TC O(n*m)
//SC O(1)
class Solution{
    private:
    bool isSafeCheck(int i,int j,int n,int m){
        return (i < n && j < m && i>=0 && j>=0);
    }
    public:
    vector<vector<int>> computeBeforeMatrix(int N, int M, vector<vector<int>> after){
        // Code here
        for(int i=N-1;i>=0;i--){
            for(int j=M-1;j>=0;j--){
                if(isSafeCheck(i-1,j,N,M)){
                    after[i][j]-=after[i-1][j];
                }
                if(isSafeCheck(i,j-1,N,M)){
                    after[i][j]-=after[i][j-1];
                }
                if(isSafeCheck(i-1,j-1,N,M)){
                    after[i][j]+=after[i-1][j-1];
                }
            }
        }
        return after;
    }
};
