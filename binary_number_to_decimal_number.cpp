//TC O(n)
//SC O(1)
class Solution
{
	public:
		int binary_to_decimal(string str)
		{
		    // Code here.
		    int dec = 0;
		    for(int i = 0;i<str.length();i++){
		        dec = (dec<<1) + str[i]-'0';
		    }
	        return dec;
		}
};

//TC O(n)
//SC O(1)

        int binary_to_decimal(string str)
		{
		    int n = str.size();
		    
		    int num = 0;
		    
		    for(int i = 0; i < n; i++)
		    {
		        int x = str[i] - '0';
		        
		        num = num * 2 + x;
		    }
		    
		    return num;
		}
		
		
//TC O(n)
//SC O(1)	
 int binary_to_decimal(string str)
 {
     int n=str.size();
     int ans=0;
     int p=0;
     for(char i=n-1;i>=0;i--)
     {
          if(str[i]=='1')
             ans=ans+pow(2,p);
          p++;
      }
      return ans;
 }