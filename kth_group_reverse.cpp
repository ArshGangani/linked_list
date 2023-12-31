#include<iostream>
using namespace std;
//Definition for singly-linked list.

class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node* kReverse(Node* head, int k) {
    // Write your code here.

    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;
    int count = 0 ;
    while(count<k && curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(count<k)
    {
        curr = prev;
        prev = NULL;
        next = NULL;
        count = 0;
        while(curr && count<k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
    }

    if(next!=NULL)
    {
        head->next = kReverse(next,k);
    }

    return prev;
}



void InsertAtHead(Node* &head,int data)
{
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node* head=nullptr;
    InsertAtHead(head,10);

    InsertAtHead(head,20);

    InsertAtHead(head,30);

    InsertAtHead(head,40);
    print(head);
    head = kReverse(head,2);
    print(head);
    return 0;
}