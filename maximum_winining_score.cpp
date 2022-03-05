//TC O(N)
//SC O(H)
class Solution {
  public:
    //Function to return maximum path product from any node in a tree.
    long long ans = 0;
    void dfs(Node* root,long long cur){
        if(!root) return;
        
        cur = cur*root->data;
        ans = max(ans,cur);
        dfs(root->left,cur);
        dfs(root->right,cur);
    }
    long long findMaxScore(Node* root)
    {
        // Your code goes here
        if(!root) return 0;
        dfs(root,1);
        return ans;
    }
};

//TC O(N)
//SC O(H)
class Solution {
  public:
    //Function to return maximum path product from any node in a tree.
    long long findMaxScore(Node* root)
    {
        // Your code goes here
        if(!root) return 1;
    
        return root->data * max(findMaxScore(root->left), findMaxScore(root->right));
    }
};

//TC O(N)
//SC O(H)
class Solution {
  public:
    //Function to return maximum path product from any node in a tree.
    long long findMaxScore(Node* root)
    {
        // Your code goes here
        if(!root) return 1;
        long long left = findMaxScore(root->left);
        long long right = findMaxScore(root->right);
        
        return root->data * max(left,right);
    }
};

//TC O(N)
//SC O(H)
class Solution {
  public:
    //Function to return maximum path product from any node in a tree.
    long long findMaxScore(Node* root)
    {
        if(!root) return 0;
        queue<pair<Node*, long long>>q;
        long long ans = 0;
        q.push({root,1});
        while(!q.empty()){
            auto x = q.front(); q.pop();
            long long cur = x.second * x.first->data;
            ans = max(ans, cur);
            if(x.first->left) q.push({x.first->left,cur});
            if(x.first->right) q.push({x.first->right,cur});
        }
        return ans;
    }
};

