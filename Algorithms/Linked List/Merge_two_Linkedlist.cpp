#include<iostream>
using namespace std;


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}


Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    if(head1==0) 
    return head2;
    if(head2==0)
    return head1;
    if(head1->data > head2->data) 
    swap(head1, head2);
    Node* ans = head1;
    while(head1 && head2){
        Node* temp = NULL;
        while(head1 && head1->data <= head2->data){
            temp = head1;
            head1 = head1->next;
        }
        temp->next = head2;
        swap(head2, head1);
    }
      return ans;

}  
