#include <stdio.h>
#include <stdlib.h>
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

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void insert(int n1)
{
    int n, value;
    n = n1;
    struct Node *temp;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

class Solution
{
public:
    void linkdelete(struct Node *head, int M, int N)
    {
        struct Node *trav = head;
        int m = M, n = N;
        int i = 0;
        while (trav != NULL)
        {
            m--;
            while (m-- > 0 && trav != NULL)
                trav = trav->next;
            // cout<<trav->data<<endl;

            while (trav != NULL && n-- > 0 && trav->next != NULL)
            {
                // cout<<"in";
                struct Node *temp = trav->next;
                // cout<<i;
                trav->next = trav->next->next;
                free(temp);
            }
            // i++;
            if (trav != NULL)
                trav = trav->next;
            m = M;
            n = N;
        }
    }
};

int main()
{
    int t, n1;
    cin >> t;
    while (t--)
    {
        cin >> n1;
        int m, n;
        cin >> m;
        cin >> n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start, m, n);
        printList(start);
    }

    return 0;
}