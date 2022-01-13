//Time Complexity O(n)
//Space Complexity O(n)

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int>st;
    while(k--){
        int n = q.front();
        q.pop();
        st.push(n);
    }
    queue<int>que;
    while(!st.empty()){
        int n = st.top();
        st.pop();
        que.push(n);
    }
    while(q.size()!=0){
        int n = q.front();
        q.pop();
        que.push(n);
    }
    
    return que;
}

//Time Complexity O(n)
//Space Complexity O(n)

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    vector<int>v;
    while(!q.empty()){
        int n = q.front();q.pop();
        v.push_back(n);
    }
    reverse(v.begin(),v.begin()+k);
    for(auto e: v) q.push(e);
    return q;
}

//Time Complexity O(n)
//Space Complexity O(n)

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
   int n = q.size() ;
   
   stack<int> st ;
   
   int i = 0 ;
   
   for(;i<k;i++)
   {
       st.push(q.front()) ; q.pop() ;
   }
   
   while(!st.empty())
   {
       q.push(st.top()) ; st.pop() ;
   }
   
   for(;i<n;i++)
   {
       q.push(q.front()) ; q.pop() ;
   }
   
   return q ;
}