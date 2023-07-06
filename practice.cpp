#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void InsertAtHead(node* &head,int data)
{
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(node* &head,int data)
{
    node* temp =head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    node* newnode = new node(data);
    temp->next = newnode;
}

void InsertatPosition(node* head,int data,int position)
{
    if(head == NULL || position==1)
    {
        InsertAtHead(head,data);
        return;
    }
    node* temp = head;
    int cnt = 1;
    while(cnt < position)
    {
        temp = temp->next;
        cnt++;
    }
    if(temp==NULL)
    {
        InsertAtTail(head,data);
        return;
    }
    node* newnode = new node(data);
    newnode->next = temp->next;
    temp->next = newnode;
}

void print(node* &head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node* node1 = new node(10);
    node* head = node1;
    
    InsertAtHead(head,5);
    print(head);

    InsertAtTail(head,5);
    print(head);
}