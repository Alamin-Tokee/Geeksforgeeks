//TC O(n^2)
//SC O(n)
class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string prefix=arr[0],ans="";
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<arr[i].length();j++)
            {
                if(prefix[j]==arr[i][j])
                    ans=ans+prefix[j];
                else
                    break;
            }
            prefix=ans;
            ans="";
        }
        if(prefix=="")
            return "-1";
        return prefix;
    }
};