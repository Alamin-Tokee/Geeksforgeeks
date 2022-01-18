//TC O(n) number nodes
//SC O(H) height of the tree
class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int dfs(Node* root,unordered_map<Node*,int>&dp){
        if(!root) return 0;
        
        if(dp[root]) return dp[root];
        int include = root->data;
        if(root->left){
            include += dfs(root->left->left, dp);
            include += dfs(root->left->right, dp);
        }
        if(root->right){
            include += dfs(root->right->left, dp);
            include += dfs(root->right->right, dp);
        }
        
        int exclude = dfs(root->left, dp) + dfs(root->right, dp);
        dp[root] = max(include, exclude);
        
        return dp[root];
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
        if(!root) return 0;
        unordered_map<Node*,int>dp;
        return dfs(root,dp);
    }
};


//TC O(n) number nodes
//SC O(H) height of the tree
class Solution{
public:
    vector<int> helper(Node* root){
       if(!root) return vector<int>{0,0};
       vector<int> left = helper(root->left);
       vector<int> right = helper(root->right);
       
       int take = root->data + left[1] + right[1]; 
       int nottake = max(left[0], left[1]) + max(right[0], right[1]); 
       return vector<int>{take, nottake};
   }
   
   int getMaxSum(Node *root) 
   {
       // Add your code here
       vector<int> res = helper(root);
       return max(res[0], res[1]);
   }
};


//TC O(n) number nodes
//SC O(H) height of the tree
class Solution{
  public:
    pair<int,int> solve(Node* root){
        if(root==nullptr){
            return {0,0};
        }
        
        pair<int,int> l = solve(root->left);
        pair<int,int> r = solve(root->right);
        
        pair<int,int> ans;
        ans.first = root->data + l.second + r.second;
        ans.second = max(l.first,l.second) + max(r.first,r.second);
        
        return ans;
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root){
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }
};