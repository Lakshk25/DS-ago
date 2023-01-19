#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor

    // Insertion
    void insertAtHead(Node *&head, Node *&tail, int data)
    {
        // empty list
        if (head == NULL)
        {
            Node *temp = new Node(data);
            head = temp;
            tail = temp;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = head;
            head = temp;
        }
    }

    void insertAtTail(Node *head, Node *&tail, int data)
    {
        if (tail == NULL)
        {
            Node *temp = new Node(data);
            tail = temp;
            head = temp;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
        }
    }

    void insertAtMiddle(Node *&head, Node *&tail, int data, int position)
    {
        if (position == 1)
        {
            insertAtHead(head, tail, data);
            return;
        }
        Node *newNode = new Node(data);
        Node *temp = head;
        int count = 0;
        while (count < position - 2)
        {
            temp = temp->next;
            count++;
        }
        if (newNode->next == NULL)
        {
            insertAtTail(head, tail, data);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void traverse(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Deletion
    void deleteHead(Node *&head)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void deleteNode(Node *&head, Node *&tail, int position)
    {
        if (position == 1)
        {
            deleteHead(head);
            return;
        }
        else
        {
            Node *curr = head;
            Node *prev = NULL;
            int count = 0;
            while (count < position - 1)
            {
                prev = curr;
                curr = curr->next;
                count++;
            }
            if (curr->next == NULL)
            {
                tail = prev;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
};
Node *solve(Node *first, Node *second)
{
    // if only one node present
    if(first -> next == NULL){
        first -> next = second;
        return first;
    }
    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}
Node *sortTwoLists(Node *first, Node *second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }
    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}
int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(3);
    Node *head1 = node1;
    Node *tail1 = node1;
    Node *head2 = node2;
    Node *tail2 = node2;
    head1->insertAtTail(head1, tail1, 2);
    head1->insertAtTail(head1, tail1, 5);
    head1->insertAtTail(head1, tail1, 7);
    head2->insertAtTail(head2, tail2, 4);
    head2->insertAtTail(head2, tail2, 6);
    head2->insertAtTail(head2, tail2, 9);
    head1->traverse(head1);
    head2->traverse(head2);
    Node *newNode = sortTwoLists(head1, head2);
    newNode->traverse(newNode);
    return 0;
}