//TC O(n)
//SC O(n)
class Solution{
    public:
    string newIPAdd (string s){
      //code here.
      string str="",res="",word;
           
        for (int i = 0; i < s.length(); ++i){
            if(s[i]=='.') s[i] = ' ';
        }
        stringstream ss;
        ss<<s;
        while(ss>>word){

            int len = word.length();
            for (int i = 0; i <len; ++i){
                if(word[i]!='0')break;
                else{
                    word.erase(0,1);
                    i--;
                } 
            }
            if(word=="") word+='0';
            res+=word+'.';
        }
        res.pop_back();
        return res;
  }
};

//TC O(n)
//SC O(n)
class Solution{
public: 
    string newIPAdd (string s){
        string ans = "";
        int l = s.size();
        for(int i=0;i<l;i++){
            string temp = "";
            while(i<l and s[i]=='0')i++;
            while(i<l and s[i]!='.')temp+=s[i++];
            if(temp.size()==0) temp = '0';
            if(i<l) ans = ans + temp + '.';
            else ans += temp;
        }
        return ans;
    }
};
