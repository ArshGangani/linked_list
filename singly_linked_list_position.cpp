//singly linked list at position
#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtHead(node* &head,int data)
{
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void InsertAtPosition(int position,node* &head,int data)
{
    if(position == 1)
    {
        InsertAtHead(head,data);
        return;
    }
    node* temp = head;
    int cnt = 1;

    while (cnt < position-1)
    {
        temp = temp->next;
        cnt++;
    }

    node* node_to_insert = new node(data);

    node_to_insert->next = temp->next;

    temp->next = node_to_insert;
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

int main()
{
    // created a new node
    node* node1 = new node(10);
    
    // head pointed to node1
    node* head = node1;
    
    print(head);

    // Inserting value at head
    InsertAtHead(head,12);
    
    print(head);

    // Inserting value at tail 
    InsertAtHead(head,100);

    print(head);

    // Inserting at 3rd position
    InsertAtPosition(3,head,5);
    print(head);
    InsertAtPosition(1,head,5);

    print(head);
    return 0;
}