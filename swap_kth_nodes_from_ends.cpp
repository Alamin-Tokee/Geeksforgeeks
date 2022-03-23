Node *swapkthnode(Node* head, int n, int k)
{
    // Your Code here
    if(k > n || k == n - k + 1) return head;
    Node* dummy = new Node(0);
    dummy->next = head;
    int first = min(k, n - k + 1);
    int second = n - first + 1;
    Node* a = dummy;
    for(int i = 0; i < first-1 ; i++){
        a = a->next;
    }
    Node* b = a;
    for(int i = 0; i < second - first; i++) {
        b = b->next;
    }
    Node* temp = a->next;
    a->next = b->next;
    b->next = temp;
    temp = a->next->next;
    a->next->next = b->next->next;
    b->next->next = temp;
    return dummy->next;
}
