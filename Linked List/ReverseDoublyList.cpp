#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory delete for node with data " << data << endl;
    }
};
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
        tail->next = temp;
        temp->prev = tail;
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
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}
void deleteNode(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
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
            prev->next = NULL;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
        else
        {
            prev->next = curr->next;
            curr->next->prev = prev;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
    }
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
void rTraverse(Node*head , Node *tail){
    Node *temp = tail;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> prev;
    }cout<<endl;
}
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        curr -> prev = next;
        prev = curr;
        curr = next;
    }
    return prev;
}
int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, tail, 4);
    insertAtTail(head, tail, 6);
    insertAtMiddle(head, tail, 0, 1);
    insertAtMiddle(head, tail, 10, 3);
    traverse(head);
    rTraverse(head ,tail);
    Node* newNode = reverse(head);
    rTraverse(head ,tail);
    traverse(newNode);
    return 0;
}