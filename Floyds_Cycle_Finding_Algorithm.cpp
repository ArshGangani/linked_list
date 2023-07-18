// floyds algorithm
//time complexity - O(n)
//space complexity - O(1)

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int value)
    {
        this->data=value;
        this->next=NULL;
    }

};

void InsertAtHead(node* &head,int data)
{
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void print(node* &head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* detectloop(node* head)
{
    node* slow = head;
    node* fast = head;
    // below loop will detect loop is present or not
    while (slow!=NULL && fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if(slow==fast)
        {
            break;
        }
    }
    if(slow==NULL || fast==NULL)
    {
        cout << "No loop exist";
        return head;
    }
    else
    {
        // below code will find first element of the loop starts
        node* intersection = fast;
        slow=head;
        while(slow!=intersection)
        {
            slow=slow->next;
            intersection=intersection->next;
        }
        cout << "loop starts with " << slow->data;
        return head;
    }
    
}

int main()
{
    node* head = new node(10);
    node* tail=head;
    InsertAtHead(head,15);
    InsertAtHead(head,60);
    cout << tail->data << endl;
    tail->next = head->next;
    // print(head);
    detectloop(head);

    return 0;
}