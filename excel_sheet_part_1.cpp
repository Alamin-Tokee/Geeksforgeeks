//TC O(logn)
//SC O(1)
class Solution{
    public:
    string ExcelColumn(int N)
    {
        // Your code goes here
        string ans = "";
        while(N > 0){
            ans=(char)((N-1)%26+'A') + ans;
            N = (N-1)/26;
        }
        
        return ans;
    }
};

//TC O(logn)
//SC O(1)
class Solution{
    public:
    string ExcelColumn(int N)
    {
        // Your code goes here
        string ans = "";
        while(--N >= 0){
            ans=(char)(N%26+'A') + ans;
            N = N/26;
        }
        
        return ans;
    }
};

//TC O(n)
//SC O(1)
class Solution{
    public:
    string ExcelColumn(int N)
    {
        // Your code goes here
        for(N;N>0;N=((N%26==0)?(N/26)-1:N/26))
            s=(char)('A'-1+((N%26==0)?26:N%26))+s;
        return s;
    }
};


//TC O(logn)
//SC O(logn)
class Solution{
    public:
    string ExcelColumn(int N){
        char a[26];
        for(int i=0;i<26;i++){
            a[i]=char(65+i);
        }
        string res = "";
        while(N>0){
            int y=(N-1)%26;
            res=a[y]+res;
            N=(N-1)/26;
        }
        // reverse(res.begin(),res.end());
        
        return res;
    }
};
