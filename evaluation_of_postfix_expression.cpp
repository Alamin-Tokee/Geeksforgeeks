class Solution{
{
    public:
    //Function to evaluate a postfix expression.
    int send(int a,int b,char ch){
        switch(ch){
            case '+' : return b+a;
            case '-' : return b-a;
            case '*' : return b*a;
            case '/' : return b/a;
        }
    }
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>st;
        int a,b;
        for(int i=0;i<S.length();i++){
            if(S[i] >= '0' && S[i] <= '9') st.push(S[i]-'0');
            else{
                a = st.top();st.pop();
                b = st.top();st.pop();
                st.push(send(a,b,S[i]));
            }
        }
        return st.top();
    }
};

//TC O(|S|)
//SC O(|S|)
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>st;
        int a,b;
        for(int i=0;i<S.length();i++){
            if(S[i] >= '0' && S[i] <= '9') st.push(S[i]-'0');
            else{
                a = st.top();st.pop();
                b = st.top();st.pop();
                if(S[i] == '+') st.push(b+a);
                else if(S[i]=='-') st.push(b-a);
                else if(S[i]=='*') st.push(b*a);
                else st.push(b/a);
            }
        }
        return st.top();
    }
};