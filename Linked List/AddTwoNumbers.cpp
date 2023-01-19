#include <iostream>
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
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is deleted for data " << value << endl;
    }
};
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
void insertAtTail(Node *&head, Node *&tail, int data)
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

Node *reverseLinkedList(Node *head)
{
    // Iterative
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
Node *addNum(Node *&first, Node *&second)
{
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
        {
            val1 = first->data;
        }
        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
        }
        int sum = val1 + val2 + carry;

        int digit = sum % 10;
        // to add digit
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;
        if (first != NULL)
            first = first->next;
        if (second != NULL)
            second = second->next;
    }
    return ansHead;
}
Node *addNumbers(Node *first, Node *second)
{
    // reverse list
    first = reverseLinkedList(first);
    second = reverseLinkedList(second);

    // add two linked list
    Node *ans = addNum(first, second);
    ans = reverseLinkedList(ans);
    return ans;
}
int main()
{
    Node *node1 = new Node(5);
    Node *node2 = new Node(5);
    Node *head1 = node1;
    Node *tail1 = node1;
    Node *head2 = node2;
    Node *tail2 = node2;
    insertAtTail(head1, tail1, 6);
    insertAtHead(head1, tail1, 3);
    insertAtHead(head2, tail2, 1);
    insertAtHead(head2, tail2, 1);
    traverse(head1);
    traverse(head2);
    Node *newHead = addNumbers(head1 , head2);
    traverse(newHead);
    return 0;
}