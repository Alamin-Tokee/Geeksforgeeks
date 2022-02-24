//TC O(n^2)
//SC O(1)
class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        //code here
        Node* i = head_ref;
        while(i){
            Node* j = i->next;
            while(j){
                if(j->data < i->data){
                    swap(i->data,j->data);
                }
                j=j->next;
            }
            i=i->next;
        }
        return head_ref;
    }
};

//TC O(n^2)
//SC O(1)
class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        Node* min = head_ref;
        Node* temp1 = head_ref;
        Node* temp2 = head_ref;
        
        while(temp1!=NULL){
            min = temp1;
            temp2=temp1;
            while(temp2!=NULL){
                if(temp2->data < min->data){
                    min = temp2;
                }
                temp2=temp2->next;
            }
            auto temp = min->data;
            min->data = temp1->data;
            temp1->data = temp;
            temp1 = temp1->next;
        }
        return head_ref;
    }
};