//TC O(n*k)
//SC O(1)
class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* merge(Node* a, Node* b){
        if(!a) return b;
        if(!b) return a;
        if(a->data<b->data){
            a->next=merge(a->next,b);
            return a;
        }else{
            b->next=merge(a,b->next);
            return b;
        }
    }
    Node * mergeKLists(Node *arr[], int N){
    // Your code here
        Node* res=NULL;
        for(int i=0;i<N;i++){
            res=merge(res,arr[i]);
        }
        return res;
    }
};

//TC O(nk Logk)
//SC O(k)
class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int N){
      // Your code here
        priority_queue<int,vector<int>,greater<int>>pq;
        Node* t=arr[0];
        for(int i=0;i<N;i++){
            while(arr[i]){
                pq.push(arr[i]->data);
                arr[i] = arr[i]->next;
            }
        }
        Node* temp = new Node(0), *head = nullptr;
        head=temp;
        while(pq.size()>0){
            temp->next=new Node(pq.top());
            pq.pop();
            temp=temp->next;
        }
        return head->next;
    }
};


//TC O(nk Logk)
//SC O(k)
class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int N){
       // Your code here
        priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>pq;
        for(int i=0;i<N;i++){
            pq.push({arr[i]->data,arr[i]});
        }
        if(pq.size()==0) return NULL;
        Node* ans = new Node(0), *t=ans;
        while(pq.size()){
            auto it=pq.top().second;
            pq.pop();
            if(it->next){
                pq.push({it->next->data, it->next});
            }
            t->next = it;
            t = it;
        }
        return ans->next;
    }
};