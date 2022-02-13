//TC O(n)
//SC O(n)
class Solution
{
    public:
    void dfs(Node* root, vector<int>& result,int level){
        if(!root) return;
        if(level == result.size()){
            result.push_back(root->data);
        }else{
            result[level] = max(root->data, result[level]);
        }
        dfs(root->left,result,level+1);
        dfs(root->right,result,level+1);
    }
    vector<int> largestValues(Node* root){
        //code here
        vector<int>result;
        if(!root) return result;
        dfs(root,result,0);
        
        return result;
    }
};

//TC O(n)
//SC O(n)
class Solution
{
    public:
    vector<int> largestValues(Node* root){
        vector<int>ans;
        function<void(Node*, int)> dfs = [&] (Node* root,int level){
            if(!root) return;
            if(ans.size() <= level) ans.push_back(0);
            ans[level] = max(ans[level], root->data);
            dfs(root->left, level+1);
            dfs(root->right, level+1);
        };
        dfs(root, 0);
        return ans;
    }
};

//TC O(n)
//SC O(n)
class Solution
{
    public:
    vector<int> largestValues(Node* root){
        if(!root) return {};
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int ma = INT_MIN;
            while(n--){
                auto node = q.front();
                q.pop();
                ma = max(ma, node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(ma);
        }
        return ans;
    }
};
