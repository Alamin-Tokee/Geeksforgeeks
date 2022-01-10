//Time Complexity O(n)
//Space Complexity O(1)
class Solution
{
    public:
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr!=NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        if(head == NULL) return head;
        
        head = reverse(head);
        Node* curr = head;
        Node* last = head;
        
        int carry = 0;
        
        while(curr){
            int sum = 0;
            if(curr == head) sum += curr->data + carry + 1;
            else sum = curr->data + carry;
            carry = sum / 10;
            curr->data = sum % 10;
            last = curr;
            curr = curr->next;
        }
        if(carry){
            Node* temp = new Node(carry);
            last->next = temp;
        }
        head = reverse(head);
        
        return head;
    }
};

//Time Complexity O(n)
//Space Complexity O(n)
class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        Node *newhead = new Node(0);
        newhead->next = head;
        
        stack<Node*> stk;
        stk.push(newhead);
        while(stk.top()->next)
            stk.push(stk.top()->next);
        
        int cy = 1;
        while(!stk.empty()) {
            stk.top()->data += cy;
            cy = stk.top()->data/10;
            stk.top()->data %= 10;
            stk.pop();
        }
        
        if(newhead->data) return newhead;
        return head;
    }
};

//Time Complexity O(n)
//Space Complexity O(1)
void solve(Node *head,int &sum,int &carry){
        if(head == nullptr){
            return;
        }
        solve(head->next,sum,carry);
        sum = carry+head->data;
        carry = sum/10;
        sum = sum%10;
        head->data = sum;
    }
    Node* addOne(Node *head) 
    {   
        int sum = 0,carry = 1;//will add atlast
        solve(head,sum,carry);
        if(carry != 0){
            Node *newHead = new Node(carry);
            newHead->next = head;
            return newHead;
        }
        else{
            return head;
        }
    }

//Time Complexity O(n)
//Space Complexity O(1)
class Solution{
   int helper(Node* head)
   {
       if(head == NULL)
           return 1;
       
       int newData = (helper(head->next) + head->data); 
       head->data = newData % 10;
       return newData / 10;
   }
   
   public:
   Node* addOne(Node *head) 
   {
       helper(head);
       
       if(head->data == 0)
       {
           Node* node = new Node(1);
           node->next = head;
           head = node;
       }
       
       return head;
   }
};

//Time Complexity O(n)
//Space Complexity O(1)
 Node* addOne(Node *head) {
    //   1->9->1->9->9->9;
       Node* temp = head;
       auto sitting = head;
       while(temp){
           if(temp->data < 9) sitting = temp;
           temp = temp->next;
       }
       if(sitting == head && sitting->data==9){
           Node* newnode = new Node(1);
           newnode->next = head;
           head->data = 0;
           head = newnode;
       }
       else sitting->data = sitting->data + 1;
       
        while(sitting->next){
            sitting->next->data = 0;
            sitting = sitting->next;
        }
       return head;
    }

//Time Complexity O(n)
//Space Complexity O(1)
    
    int addOneInRecurisveWay(Node* head){
       if(!head) return 1;
       int carry = 0;
       head->data += addOneInRecurisveWay(head->next);
       if(head->data == 10){
           head->data = 0;
           return 1;
       }
       if(head->data <= 9)return 0;
       
       head->data %= 10;
       carry /= head->data;
       return carry;
   }
   
   Node* addOne(Node *head) 
   {
       int carry = addOneInRecurisveWay(head);
       head->data = carry * 10 + head->data;
       return head;
   }