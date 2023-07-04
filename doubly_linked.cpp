#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~node()
    {
        int value = this->data;
        if(next!=NULL)
        {
            delete this->next;
            this->next = NULL;
        }
        cout << "Memory free for node value :- " << value << endl;
    }
};



void print(node* &head)
{
    node* temp = head;
    while (temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(node* head)
{
    int cnt=0;
    node* temp = head;

    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

void InsertAtHead(node* &tail,node* &head,int data)
{
    //empty list
    if(head == NULL)
    {
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        node* newnode = new node(data);
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void InsertAtTail(node* &tail,node* &head,int data)
{
    if(tail == NULL)
    {
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        node* newnode = new node(data);
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void InsertAtPosition(node* &tail,node* &head,int position,int data)
{
    if(position == 1)
    {
        InsertAtHead(tail,head,data);
    }
    else
    {
        node* temp = head;
        int cnt = 1;
        while(cnt < position-1)
        {
            cnt++;
            temp = temp->next;
        }

        if(temp->next == NULL)
        {
            InsertAtTail(tail,head,data);
            return;
        }

        node* newnode = new node(data);
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void deleteNode(int position,node* &head,node* &tail)
{
    if(position == 1)
    {
        node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        head->next = NULL;
        delete temp;
    }
    else
    {
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < position)
        {
            cnt++;
            prev = curr;
            curr = curr->next;
        }
        
        if(curr->next == NULL)
        {
            tail = curr->prev;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

int main()
{
    
    node* head = NULL;
    node* tail = NULL;

    print(head);
    cout << getLength(head) << endl;

    InsertAtHead(tail,head, 11);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    InsertAtHead(tail,head, 13);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    InsertAtHead(tail,head, 8);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    cout << getLength(head) << endl;
    InsertAtTail(tail,head, 25);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    InsertAtPosition(tail, head, 2, 100);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    InsertAtPosition(tail, head, 1, 101);
    print(head);

    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    InsertAtPosition(tail, head, 7, 102);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    deleteNode(7, head,tail);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;
    return 0;
}