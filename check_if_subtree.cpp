//TC O(n)
//SC O(H)
class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    bool dfs(Node* t, Node* s){
        if(t == NULL && s == NULL) return true;
        else if(t == NULL) return false;
        else if(s == NULL) return false;
        
        if(t->data != s->data) return false;
        
        return dfs(t->left, s->left) && dfs(t->right, s->right);
    }
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        if(S == NULL) return true;
        if(T == NULL) return false;
        
        if(dfs(T,S)) return true;
        
        return isSubTree(T->left, S) || isSubTree(T->right, S);
    }
};


bool solve(Node* root, Node* subRoot)
  {
      if(!root && subRoot)
      return false;
      if(root  && !subRoot)
      return false;
      if(!root && !subRoot)
      return true;
      if(root->data!=subRoot->data)
      return false;
      return solve(root->left,subRoot->left) && solve(root->right,subRoot->right);
  }
    
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        queue<Node*> q;
        q.push(T);
        while(!q.empty())
        {
            Node* t=q.front();
            q.pop();
            if(t->data==S->data)
            {
                if(solve(t,S))
                return true;
            }
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);
        }
        return false;
    }


int ifSubtree(Node* T, Node* S)
{
    if(T==nullptr&&S==nullptr)
    return 1;
    else if (T==nullptr||S==nullptr)
    return 0;
    
    if(T->data==S->data)
    {
        if(ifSubtree(T->left,S->left)==1&&ifSubtree(T->right,S->right)==1){
            return 1;
        }else
        {
            return 0;
        }
    }
}
class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        if(T==nullptr)
        {
            return 0;
        }
     if(T->data==S->data)
     {
        if(ifSubtree(T,S)==1)
        return 1;
     }
     if(isSubTree(T->left,S)==1)
     {
         return 1;
     }
     if(isSubTree(T->right,S)==1)
     {
         return 1;
     }
     return 0;
    }
};