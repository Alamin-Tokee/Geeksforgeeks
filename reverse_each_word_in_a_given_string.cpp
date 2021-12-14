class Solution{
  public:
    string getReverseWord(string word){
        string result="";
        int sz=word.size();
        while(sz-->0){
            result+=word[sz];
        }
        return result;
    }
    string reverseWords (string s)
    {
        int n=s.length();
        string t="";
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                ans+=getReverseWord(t)+'.';
                t="";
            }
            else t+=s[i];
        }
        if(t!="") ans+=getReverseWord(t);
        
        return ans;
    }
};
class Solution{
{
  public:
    string reverseWords (string s)
    {
        // //code here.
        // stringstream ss(s);
        // string ans="";
        // string temp;
        // while(getline(ss, temp, '.')){
        //     reverse(temp.begin(),temp.end());
        //     ans.append(temp);
        //     ans.push_back('.');
        // }
        // ans.pop_back();
        //  //ans.substr(0,ans.size()-1);
        // return ans;
        string t,ans;
        for(auto c : s){
            if(c=='.'){
                reverse(t.begin(),t.end());
                ans+=t+".";t.clear();
            }else t.push_back(c);
        }
        reverse(t.begin(),t.end());
        return ans+t;
    }
};


string reverseWords (string s)
    {
        string ss="";
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!='.'){
                st.push(s[i]);
            }else{
                while(!st.empty()){
                    ss+=st.top();
                    st.pop();
                }
                ss+='.';
            }
        }
        while(!st.empty()){
            ss+=st.top();
            st.pop();
        }
        return ss;
    }



// C++ program to understand the use of getline() function

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S, T;

	getline(cin, S);

	stringstream X(S);

	while (getline(X, T, ' ')) {
		cout << T << endl;
	}

	return 0;
}