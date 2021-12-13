//Time Complexity (n*k)
//Space Complexity O(1)

int listLength(Node* head){
    int c=0;
    while(head->next){
        c++;
        head=head->next;
    }
    return c;
}
int fractional_node(struct Node *head, int k)
{
    // your code here
    int n=listLength(head);
    int m=ceil(n/k);
    int count = 0;
    while(count < m){
        count++;
        head=head->next;
    }
    return head->data;
}

//Better
//Time Complexity O(n)
//Space Complexity O(1)
int fractional_node(struct Node *head, int k)
{
    Node* slow=head,*fast=head;
    while(fast){
        for(int i=0;fast&&i<k;i++) fast=fast->next;
        if(fast) slow=slow->next;
    }
    return slow->data;
}