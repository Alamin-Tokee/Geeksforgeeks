   class Solution{
    public:
        int closestToZero(int arr[], int n)
        {
            // your code here 
            sort(arr,arr+n);
            int ans=INT_MAX;
            int i=0,j=n-1;
            while(i<j){
                int x=arr[i]+arr[j];
                if(abs(ans) > abs(x)){
                    ans=x;
                }
                if(abs(ans)==abs(x)){
                    ans=max(ans,x);
                }
                if(x < 0){
                    i++;
                }else{
                    j--;
                }
            }
            return ans;
        }
};