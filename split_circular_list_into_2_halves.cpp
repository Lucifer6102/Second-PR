void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node*temp=head->next;
    int l=1;
    while(temp!=head)
    {
        l++;
        temp=temp->next;
    }
    //cout<<l<<"\n";
    if(l%2==0)
    {
        Node* x=head;
        int h=l/2;
        while(h!=1)
        {
            h--;
            x=x->next;
        }
        h=l/2;
        Node* y=x->next;
        Node* t=x->next;
        x->next=head;
        *head1_ref=head;
        while(h!=1)
        {
            h--;
            y=y->next;
        }
        y->next=t;
        y=y->next;
        *head2_ref=y;
    }
    else
    {
        Node* x=head;
        int h=l/2;
        while(h!=0)
        {
            h--;
            x=x->next;
        }
        h=l/2;
        Node* y=x->next;
        Node* t=x->next;
        x->next=head;
        *head1_ref=head;
        while(h!=1)
        {
            h--;
            y=y->next;
        }
        y->next=t;
        y=y->next;
        *head2_ref=y;
    }
}

// Time - O(n)
// Space - O(1)