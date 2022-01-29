//O(|S|)
//O(|S|)
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        stack<string> st;
        string temp = "";
        for(int i=0;i<S.length();i++){
            if(S[i]=='.') {
                st.push(temp);
                temp = "";
            }
            else temp+=S[i];
        }
        if(temp!="") st.push(temp);
        
        string ans = "";
        while(!st.empty()){
            ans+= st.top() + '.';
            st.pop();
        }
        return ans.substr(0,S.length());
    } 
};

//O(|S|)
//O(|S|)
class Solution{
    public:
    string reverseWords(string S) { 
        // code here 
        string ans = "";
        string temp = "";
        for(int i=S.length()-1;i>=0;i--){
            if(S[i] == '.'){
                ans += temp;
                ans += S[i];
                temp = "";
            }else{
                temp = S[i]+temp;
            }
        }
        ans += temp;
        return ans;
    }
}

//O(|S|)
//O(|S|)
class Solution{
    public:
    string reverseWords(string S) { 
       // code here 
       string s="";
       vector<string>v;
       for(int i=0;i<S.length();i++)
       {
           if(S[i]=='.'){
               v.push_back(s);
               s="";
           }else{
               s+=S[i];
           }
       }
       v.push_back(s);
       s="";
       for(int i=v.size()-1;i>=0;i--)
       {
           if(i==0) s+=v[i];
           else s+=v[i]+".";
       }
       return s;
   } 
}