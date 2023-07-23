// check palindrome time complexity O(n) and space complexity O(1)

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution
{
private:
    Node *middle(Node *head)
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        Node *fast;
        if (count % 2 == 0)
            fast = head->next;
        else
            fast = head;
        Node *slow = head;
        while (fast->next != NULL && fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *Reverselist(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        // Your code here
        if (head->next == NULL)
            return true;
        Node *mid = middle(head);
        mid->next = Reverselist(mid->next);
        Node *temp1 = head;
        Node *temp2 = mid->next;
        while (temp2 != NULL)
        {
            if (temp1->data != temp2->data)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};

int main()
{
    return 0;
}