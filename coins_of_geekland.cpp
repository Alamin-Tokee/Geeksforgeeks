//TC O(n^2)
//SC O(n^2)
class Solution{    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int K){
        // Your code goes here
        for(int row=1;row<N;row++){
            for(int col=0;col<N;col++){
                mat[row][col]+=mat[row-1][col];
            }
        }
        for(int row=0;row<N;row++){
            for(int col=1;col<N;col++){
                mat[row][col]+=mat[row][col-1];
            }
        }
        int sum = 0, maxSum = 0;
        
        for(int row=K-1;row<N;row++){
            for(int col=K-1;col<N;col++){
                sum=mat[row][col];
                if((row-K)>=0) sum-=mat[row-K][col];
                if((col-K)>=0) sum-=mat[row][col-K];
                if((row-K)>=0 && (col-K)>=0) sum+=mat[row-K][col-K];
                
                maxSum = max(maxSum,sum);
            }
        }
        return maxSum;
    }  
};

//TC O(n^2)
//SC O(n^2)
class Solution{
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int n,int k){
       if(k>n)
        return 0;
      
        for(int i=0;i<n;i++)
        {
            int sum=0;int j=0;
            while(j<k){
                sum+=mat[i][j++];
            }
            while(j<n){
                int temp=sum;
                sum+=(mat[i][j]-mat[i][j-k]);
                mat[i][j-k]=temp;
                j++;
                if(j==n)
                {
                    mat[i][j-k]=sum;
                }
            }
        }
        
        int ans=INT_MIN;
        for(int j=0;j<(n-k+1);j++)
        {
            int sum=0;int i=0;
            while(i<k){
                sum+=mat[i++][j];
            }
            while(i<=n){
                ans=max(ans,sum);
                sum+=mat[i][j]-mat[i-k][j];
                i++;
                if(i==n)
                {
                    ans=max(ans,sum);
                }
            }
        }
       return ans;
    }  
};