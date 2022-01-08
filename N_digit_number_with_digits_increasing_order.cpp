class Solution{
public:
    void helper(int n,int num,vector<int>& ans){
        if(n == 0){
            ans.push_back(num);
            return;
        }
        int lastDigit = num % 10;
        for(int i=lastDigit+1;i<=9;i++){
            helper(n-1,num*10+i,ans);
        }
    }
    vector<int> increasingNumbers(int N){
        // Write Your Code here
        vector<int> ans;
        if(N==1) ans.push_back(0);
        
        helper(N, 0, ans);
        
        return ans;
    }
};


    void help(int cur,int start,int curlen,int len,vector<int>& res){
       if(curlen==len){
           res.push_back(cur);
           return;
       }
       if(start>=10)return;
       help(cur*10+start,start+1,curlen+1,len,res);
       help(cur,start+1,curlen,len,res);
   }
   vector<int> increasingNumbers(int N)
   {
       // Write Your Code here
       vector<int>res;
       if(N==1)res.push_back(0);
       help(0,1,0,N,res);
       return res;
   }

