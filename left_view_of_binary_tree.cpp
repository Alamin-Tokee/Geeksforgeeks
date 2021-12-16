//BFS Approach
//Time Complexity O(N)
//Sapce Complexity O(H)
 vector<int> leftView(Node *root)
{
  // Your code here
  if(!root) return {};
  vector<int>ans;
  queue<Node*>q;
  q.push(root);
  while(!q.empty()){
      int sz=q.size();
      for(int i=0;i<sz;i++){
          Node* node=q.front();
          q.pop();
          if(i==0) ans.push_back(node->data);
          if(node->left) q.push(node->left);
          if(node->right) q.push(node->right);
      }
  }
  return ans;
}

//DFS Approach
//Time Complexity O(N)
//Sapce Complexity O(H)
void solve(Node *root,vector<int>&res,int level){
    if(!root) return;
    if(level==res.size()) res.push_back(root->data);
    
    solve(root->left,res,level+1);
    solve(root->right,res,level+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   if(!root) return {};
   vector<int>res;
   solve(root,res,0);
   return res;
}