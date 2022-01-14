//TC O(n)
//SC O(H)

void modifyHelper(Node* root,int& val){
    if(!root) return;
    modifyHelper(root->right,val);
    root->data += val;
    val = root->data;
    modifyHelper(root->left,val);
}
Node* modify(Node *root)
{
    // Your code here
    int val = 0;
    modifyHelper(root,val);
    return root;
}

int calSum(Node* root){
    if(!root) return 0;
    return root->data + calSum(root->left) + calSum(root->right);
}
void modifyHelper(Node* root,int& sum){
    if(!root) return;
    modifyHelper(root->left,sum);
    int temp = root->data;
    root->data = sum;
    sum = sum - temp;
    modifyHelper(root->right,sum);
}
Node* modify(Node *root)
{
    // Your code here
    int sum = calSum(root);
    modifyHelper(root,sum);
    return root;
}


void modify1(Node *&root)
{
   // Your code here
   if(((root->left)==NULL and (root->right)==NULL)||(root==NULL)){
       return;
   }
   if(root->right){
       modify1(root->right);
       Node *temp =root->right;
       while(temp->left){
           temp=temp->left;
       }
       root->data = root->data+temp->data;
   }
   if(root->left){
       
       Node *temp =root->left;
       while(temp->right){
           temp=temp->right;
       }
       temp->data = temp->data + root->data;
       modify1(root->left);
   }
}
Node *modify(Node *root){
   Node *n ;
   modify1(root);
   n= root;
   return n;
}