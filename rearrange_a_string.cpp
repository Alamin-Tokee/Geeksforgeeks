    class Solution{
    public:
    string arrangeString(string str)
    {
        //code here.
        vector<int>alpha(26,0);
        int num = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                alpha[str[i]-'A']++;
            }else{
                num += (str[i]-'0');
            }
        }
        string result = "";
        for(int i = 0; i < 26; i++){
            while(alpha[i]-- > 0){
                result += 'A' + i;
            }
        }
        result += to_string(num);
        return result;
    }
};


class Solution{
  public:
    string arrangeString(string str){
        //code here.
        string ans="";
        int sum=0;
        for(int i=0;i<str.size();i++){
            if(isdigit(str[i])){
                sum+= str[i]-'0';
            }
            else{
                ans+=str[i];
            }
        }
        sort(ans.begin(),ans.end());
        ans = ans+to_string(sum);
        return ans;
    }
};