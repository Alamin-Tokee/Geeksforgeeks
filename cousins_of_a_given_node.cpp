
//TC O(n)
//SC O(n)
class Solution
{
    public:
    vector<int>ans;
    Node* parent = NULL;
    void dfs(Node* root, int x,int l,Node* par){
        if(!root) return;
        
        if(l==x && parent!=par){
            ans.push_back(root->data);
        }
        dfs(root->left,x,l+1,root);
        dfs(root->right,x,l+1,root);
    }
    int height(Node* root,Node* x,int l,Node* par){
        if(!root) return 0;
        if(x==root){
            parent = par;
            return l;
        }
        int t = height(root->left,x,l+1,root);
        if(t) return t;
        t = height(root->right,x,l+1,root);
        return t;
    }
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        //code here
        int level = height(root, node_to_find, 0, root);
        dfs(root,level,0,root);
        if(ans.size()==0) return {-1};
        return ans;
    }
    
};

//TC O(n)
//SC O(n)

class Solution
{  
   private:
     int finddepth(Node * data,Node *root ,int depth=1)
     {
         if(root==NULL){
             return 0;
         }
         if(root==data){
             return depth;
         }
         else{
            int height1=finddepth(data,root->right,depth+1);
            int height2=finddepth(data,root->left,depth+1);
            return max(height1,height2);
       
         }
         
     }
   
   private:
   void printhelper(int depth,vector<int> & ans,Node * root, Node * data)
   {
       if(root==NULL){
           return;
       }
       if((root->left==data || root->right==data) and depth-1==1){
           return;
       }
       if(depth==1 and root!=data){
           ans.push_back(root->data);
       }
       else{
           printhelper(depth-1,ans,root->left,data);
           printhelper(depth-1,ans,root->right,data);
       }
       return;
   }
   
   public:
   vector<int> printCousins(Node* root, Node* node_to_find)
   {
       //code here
       vector<int> ans;
       int depth=finddepth(node_to_find,root);
       //cout<<"depth:"<<depth<<endl;
       printhelper(depth,ans,root,node_to_find);
       if(ans.size()==0){
           ans.push_back(-1);
       }
       return ans;
   }
};


//TC O(n)
//SC O(n)
 
class Solution
{  
   public:
 vector<int> printCousins(Node* root, Node* node_to_find)
   {
       vector<int> ans;
       queue<Node*> q;
       q.push(root);
       
       bool found = false;
       while(!q.empty() && !found)
       {
           int size = q.size();
           
           while(size--)
           {
               Node* temp = q.front();
               q.pop();
               
               if(temp->left == node_to_find || temp->right == node_to_find)
                   found = true;
               else
               {
                   if(temp->left)
                       q.push(temp->left);
                   
                   if(temp->right)
                       q.push(temp->right);
               }
           }
       }
       
       if(!q.empty())
       {
           while(!q.empty())
           {
               ans.push_back(q.front()->data);
               q.pop();
           }
       }
       else
           ans.push_back(-1);
   
       return ans;
   }
};