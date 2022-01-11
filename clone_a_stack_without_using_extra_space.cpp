//TC O(n)
//SC O(1)
class Solution{
    public:
    void clonestack(stack<int> st, stack<int>& cloned)
    {
        //code here
         //st.swap(cloned);
        if(st.size() == 0) return;
        int temp = st.top();
        st.pop();
        clonestack(st,cloned);
        cloned.push(temp);
        return;
    }
};

//TC O(n)
//SC O(n)
class Solution{
    public:
    void clonestack(stack<int> st, stack<int>& cloned)
    {
        int t = st.size();
        vector<int>v;
        while(st.size()){
            v.push_back(st.top());
            st.pop();
        }
        while(t--){
            cloned.push(v[t]);
        }
    }
};
