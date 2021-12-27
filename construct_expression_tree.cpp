
//Recursive Approach
//TC O(n)
//SC O(n)
//function to construct expression tree
et* make(char postfix[],int& end){
    et* root = new et(postfix[end--]);
    if(root->value == '+' || root->value == '*' || root->value == '-' || root->value =='/' || root->value == '^'){
        root->right = make(postfix,end);
        root->left = make(postfix,end);
    }
    return root;
}
et* constructTree(char postfix[])
{
//code here
    int end = strlen(postfix)-1;
    return make(postfix,end);
}

//Iterative Approach
//TC O(n)
//SC O(n)
//function to construct expression tree
et* constructTree(char postfix[])
{
//code here
    stack<et*>s;
    for(int i = 0;i < strlen(postfix); i++){
        if(isalpha(postfix[i])){
            et *node = (struct et*)malloc(sizeof(struct et));
            node->value = postfix[i];
            node->left = 0;
            node->right = 0;
            s.push(node);
        }else{
            et *node1, *node2, *node3;
            node3 = (struct et*)malloc(sizeof(struct et));
            node3->value = postfix[i];
            node2 = s.top();
            node3->right = node2;
            s.pop();
            node1 = s.top();
            node3->left = node1;
            s.pop();
            s.push(node3);
            
        }
    }
    return s.top();
}