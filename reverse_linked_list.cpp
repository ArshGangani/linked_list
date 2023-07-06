/*
    reversing link list simple
    node* reverse(node* &head)
    {
        node* prev = NULL;
        node* curr = head;
        while(curr != NULL)
        {
            node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    // time complexity O(n) and space complexity O(1)


    reversing using recursion
    node* reverse(node* &head)
    {
        node* prev = NULL;
        node* curr = head;
        reverse_recursion(head,curr,prev);
    }
    void reverse_recursion(node* &head,node curr,node prev)
    {
        if(curr == NULL)
        {
            head = prev;
            return;
        }

        node* forward = curr->next;
        reverse_recursion(head,forward,curr);
        curr->next = prev;
    }
    // time complexity O(n) and space complexity O(n)
*/
