// singly linked list at head
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
    return 0;
}