//TC O(n^2)  
//SC O(1)

struct node* partition(struct node *head,struct node *tail){
    node* curr = head->next;
    node* prev = head;
    node* pivot = head;
    while(curr!=tail->next){
        if(curr->data < pivot->data){
            swap(prev->next->data,curr->data);
            prev=prev->next;
        }
        curr=curr->next;
    }
    swap(pivot->data,prev->data);
    return prev;
}
void quickSortRecur(struct node *head,struct node *tail){
    if(head == tail || head == NULL || tail == NULL) return;
    node *pivot = partition(head,tail);
    quickSortRecur(head,pivot);
    quickSortRecur(pivot->next,tail);
}
void quickSort(struct node **headRef) {
    node* tail=*headRef;
    
    while(tail->next!=NULL){
        tail = tail->next;
    }
    quickSortRecur(*headRef,tail);
}


struct node* parti(struct node* head,struct node* tail){
    struct node* pvt = head, *curr = head->next, *prev= head;
    while(curr!=tail->next){
        if(pvt->data > curr->data){
            swap(prev->next->data,curr->data);
            prev = prev->next;
        }
        curr = curr->next;
    }
    swap(pvt->data,prev->data);
    return prev;
}
void solve(struct node* head,struct node* tail){
    if(!head || !tail || head==tail) return;
    struct node* pvt = parti(head,tail);
    solve(head,pvt);
    solve(pvt->next,tail);
}
void quickSort(struct node **head) {
    //  if(!head || !head->next) return NULL;
    struct node* tail = *head;
    while(tail->next)
        tail = tail->next;
    solve(*head,tail);
}

