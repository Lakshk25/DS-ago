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
void insertAtTail(Node* &tail , Node* curr){
    tail -> next = curr;
    tail = curr;
}
Node* sort(Node* head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    while(curr != NULL){
        int value = curr -> data;
        if(value == 0){
            insertAtTail(zeroTail , curr);
        }
        else if(value == 1){
            insertAtTail(oneTail , curr);
        }
        else if(value == 2){
            insertAtTail(twoTail , curr);
        }
        curr = curr -> next;
    }
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
    }
    else{
        zeroTail -> next = twoHead -> next;
    }
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    head = zeroHead -> next;
    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);
    return head;
}
int main()
{
    Node *node1 = new Node(0);
    Node *head = node1;
    Node *tail = node1;
    tail->insertAtTail(head, tail, 0);
    tail->insertAtTail(head, tail, 1);
    tail->insertAtTail(head, tail, 1);
    tail->insertAtTail(head, tail, 0);
    head->insertAtHead(head, tail, 2);
    head->insertAtHead(head, tail, 2);
    head->insertAtHead(head, tail, 1);
    head->insertAtHead(head, tail, 0);
    head->traverse(head);
    Node* newNode = sort(head);
    newNode->traverse(newNode);
    return 0;
}