// singly linked list at tail
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

void InsertAtTail(node* &tail,int data)
{
    node* temp = new node(data);
    tail -> next = temp;
    tail = temp;
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
    // tail pointed to node1
    node* tail = node1;
    
    print(head);

    InsertAtTail(tail,12);
    
    print(head);

    InsertAtTail(tail,100);

    print(head);
    return 0;
}