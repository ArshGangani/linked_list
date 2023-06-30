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
    ~node()
    {
        int value = this->data;
        // memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void InsertAtHead(node* &head,int data)
{
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(node* &tail,int data)
{
    node* temp = new node(data);
    tail -> next = temp;
    tail = temp;
}

void InsertAtPosition(int position,node* &tail,node* &head,int data)
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

    if(temp->next == NULL)
    {
        InsertAtTail(tail,data);
        return;
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

void DeleteNode(int position,node* &head,node* &tail)
{
    if(position==1)
    {
        node* temp = head;
        head = head->next;

        //memory free starting node
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node* prev = NULL;
        node* curr = head;
        int cnt = 1;

        while(cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr == tail)
        {
            tail = prev;
            delete curr;
            tail->next = NULL;
            return;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    // created a new node
    node* node1 = new node(10);
    
    // head pointed to node1
    node* head = node1;
    node* tail = node1;
    print(head);

    // Inserting value at head
    InsertAtHead(head,12);
    
    print(head);

    // Inserting value at tail 
    InsertAtHead(head,100);

    print(head);

    InsertAtPosition(4,tail,head,5);

    print(head);

    DeleteNode(4,head,tail);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    return 0;
}