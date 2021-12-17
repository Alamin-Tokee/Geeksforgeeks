class Node{
public:
    int freq;
    Node *left,*right;
    Node(int f){
        this->freq = f;
        this->left = this->right = nullptr;
    }
};

class Compare{
    public:
    inline bool operator()(Node* a,Node* b){
        return a->freq > b->freq; //Min heap
    }
};

class Solution
{
	public:
	void dfs(Node *root,string res,vector<string>& ans){
	    if(!root) return;
	    if(!root->left && !root->right){
	        ans.push_back(res);
	        return;
	    }
	    dfs(root->left,res+'0',ans);
	    dfs(root->right,res+'1',ans);
	}
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<Node*,vector<Node*>,Compare>pq;
		    for(int i=0;i<N;i++){
		        Node* newNode=new Node(f[i]);
		        pq.push(newNode);
		    }
		    while((int)pq.size() > 1){
		        Node *leftNode = pq.top();pq.pop();
		        Node *rightNode = pq.top();pq.pop();
		        int newFreq = leftNode->freq + rightNode->freq;
		        Node* parentNode = new Node(newFreq);
		        parentNode->left = leftNode;
		        parentNode->right = rightNode;
		        pq.push(parentNode);
		    }
		    
		    Node* root=pq.top();pq.pop();
		    vector<string> ans;
		    string res = "";
		    dfs(root,res,ans);
		    return ans;
		}
};



class Solution{
public:
    struct Node {
           int data;
           struct Node* left;
           struct Node* right;

  
       Node(int val)
       {
           data = val;
           left = NULL;
           right = NULL;
       }
   };
   
   struct cmp {

       bool operator()(Node* l, Node* r)
       
       {
       return (l->data > r->data);
       }
   };
    
    void preOrder(Node *root,string s,vector<string>&ans){
        if(!root){
            return;
        }
        
        if(!root->left && !root->right){
            ans.push_back(s);
        }
        
        preOrder(root->left,s+"0",ans);
        preOrder(root->right,s+"1",ans);
    }
    
 vector<string> huffmanCodes(string S,vector<int> f,int n)
 {
     priority_queue<Node*,vector<Node*>,cmp> mh;

     for(int i=0; i<n; i++){
         Node *temp = new Node(f[i]);
               mh.push(temp);
     }
     
     while(mh.size() != 1){
         Node *left = mh.top();
         mh.pop();
         Node *right = mh.top();
         mh.pop();
         Node *parent = new Node(left->data + right->data);
         parent->left = left;
         parent->right = right;
         mh.push(parent);
     }
     
     Node *root = mh.top();
     mh.pop();
     vector<string> ans;
     preOrder(root,"",ans);
     return ans;
     
   }
 };

