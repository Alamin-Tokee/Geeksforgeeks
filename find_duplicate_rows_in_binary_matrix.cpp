//Time Complexity O(N)
//Space Complexity O(2*N*M)
class Solution
{   
    struct Node{
        bool visited{false};
        Node* child[2]{nullptr,nullptr};
    };
    bool insert(Node* root,vector<int>&row){
        for(auto x:row){
            if(!root->child[x])
                root->child[x]=new Node;
            root=root->child[x];
        }
        bool ans=root->visited;
        root->visited=true;
        return ans;
    }
public:
vector<int> repeatedRows(vector<vector<int>> matrix, int M, int N) 
{ 
    // Your code here
    // set<vector<int>>m;
    // vector<int>ans;
    // for(int i=0;i<M;i++){
    //     if(m.find(matrix[i])!=m.end()) ans.push_back(i);
    //     else m.insert(matrix[i]);
    // }
    // return ans;
    
    // unordered_set<int>seen;
    // vector<int>ans;
    // for(int i=0;i<M;i++){
    //     int cur=0;
    //     for(int a:matrix[i]){
    //         cur <<= 1;
    //         cur += a;
    //     }
    //     if(seen.find(cur)==seen.end()){
    //         seen.insert(cur);
    //     }else{
    //         ans.push_back(i);
    //     }
    // }
    // return ans;
    Node *root=new Node;
    vector<int>ans;
    for(int i=0;i<matrix.size();i++){
        if(insert(root,matrix[i]))
           ans.push_back(i);
    }
    return ans;
} 
};