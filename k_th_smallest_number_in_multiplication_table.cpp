class Solution{       
    public:
    bool smaller(int num,int m,int n,int k){
        int count=0;
        for(int i=1;i<=m;i++){
            count+=min(num/i,n);
        }
        return count>=k;
    }
    int KthSmallest(int m, int n, int k) {
        //Write your code here
        int low=1,high=m*n;
        while(low<high){
            int mid=(low+high)/2;
            if(smaller(mid,m,n,k)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};