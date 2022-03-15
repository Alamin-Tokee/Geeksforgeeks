//TC O(N*Log(max(A[])))
//SC O(1)
class Solution{
    public:
    int count(int N, vector<int> A,int X)
    {
        // code here
        int ans = N;
        int mask = 0;
        
        for(int i=30;i>=0;i--){
            int bitVal = ((1<<i) & X);
            if(bitVal > 0) mask^=(1<<i);
            else{
                int count = 0;
                int greaterMask = (mask^(1<<i));
                for(int elem:A){
                    int val = (greaterMask & elem);
                    if(val!=greaterMask) count++;
                }
                ans = min(ans,count);
            }
        }
        return ans;
    }
};


    int count(int N, vector<int> A,int X){
       int p = 0, ans = N;
       for(int i=31; i >= 0; i--){
           int bit = (X>>i) & 1;
           if(bit == 1){
               p = p | (1<<i);
           }
           else{
               int temp = p | (1<<i);
               int cnt = 0;
               for(auto ele: A){
                   if((ele&temp) == temp){
                       cnt++;
                   }
               }
               
               ans = min(ans,N-cnt);
           }
       }
       return (ans);
    }