//Time Complexity O(N)
//Space Complexity O(H)
void dfs(Node* root,int mxx,int &ans){
    if(!root) return;
    ans=max(ans,mxx-root->data);
    mxx=max(mxx,root->data);
    dfs(root->left,mxx,ans);
    dfs(root->right,mxx,ans);
}
int maxDiff(Node* root)
{
    // Your code here 
    int ans=-1e9;
    int mxx=-1e9;
    
    dfs(root,mxx,ans);
    
    return ans;
    
}


//Time : O(N), Space O(H).

int maxDiff(Node* root)
{
    int res = INT_MIN;
    queue<pair<Node*, int>> q;
    
    //Store max ancestor value at each node.
    q.push({root, root->data});
    
    while(!q.empty()){
       pair<Node*, int> p = q.front(); q.pop();
       Node* r = p.first;
       int maxAnc = p.second;
       
       if(r->left){
           int diff = maxAnc - r->left->data;
           if(diff> res)
                res = diff;
           q.push({r->left, max(maxAnc, r->left->data)}); 
       }
       
       if(r->right){
           int diff = maxAnc - r->right->data;
           if(diff> res)
                res = diff;
           q.push({r->right, max(maxAnc, r->right->data)}); 
       }
    }
    return res;
}