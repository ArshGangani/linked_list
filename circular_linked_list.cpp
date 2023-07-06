#include<iostream>
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
        while(this->next != NULL)
        {
            delete this->next;
            this->next = NULL;
        }
        cout << "node is free from position having value:- " << value << endl;
    }
};


void InsertNode(node* &tail,int element,int d)
{
    if(tail==NULL)
    {
        node* newnode = new node(d);
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        node* temp = tail;
        while(temp->data != element)
        {
            temp = temp->next;
        }
        node* newnode = new node(d);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void print(node* &tail)
{
    node* temp = tail;

    if(tail==NULL)
    {
        cout << "ist is Empty\n";
        return;
    }

    do{
        cout << temp->data << " ";
        temp=temp->next;
    }while(temp!=tail);
    cout << endl;
}

void deletenode(node* &tail,int value)
{
    if(tail == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        node* temp = tail;
        while (temp->next->data!=value)
        {
            temp = temp->next;
        }
        node* delnode = temp->next;
        temp->next = delnode->next;
        delnode->next = NULL;
        delete delnode;
        
    }
}

bool iscircular(node* tail)
{
    if(tail==NULL)
        return true;
    node* temp = tail;
    while(temp!=NULL && tail!=temp)
    {
        temp=temp->next;
    }
    if(temp==tail)
    {
        return true;
    }
    return false;
}



int main()
{
    
    node* tail = NULL;

    InsertNode(tail, 5, 3);
    print(tail);

    InsertNode(tail, 3, 5);
    print(tail);

    InsertNode(tail, 5, 7);
    print(tail);

    InsertNode(tail, 7, 9);
    print(tail);

    InsertNode(tail, 5, 6);
    print(tail);
    
    InsertNode(tail, 9, 10);
    print(tail);

    InsertNode(tail, 3, 4);
    print(tail);

    deletenode(tail, 5);
    print(tail);

    cout << iscircular(tail) << endl;
    return 0;
}