//Time Complexity O(N)
//Space Complexity O(N)
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int>st;
        st.push(-1);
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else{
                    ans = max(ans,i-st.top());
                }
            }
        }
        return ans;
    }
};


//Time Complexity O(n)
//Space Complexity O(1)
 int findMaxLen(string s) {
        // code here
        int left=0,right=0;
        int length=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                left++;
            }else if(s[i]==')'){
                right++;
            }
            if(left==right){
                length=max(length,2*right);
            }
            if(right>left){
                left=right=0;
            }
        }
        left=right=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='('){
                left++;
            }else if(s[i]==')'){
                right++;
            }
            if(left==right){
                length=max(length,2*right);
            }
            if(left>right){
                left=right=0;
            }
        }
        return length;
        
    }
