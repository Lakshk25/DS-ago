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
Node* removeDuplicates(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node *curr = head;
    while(curr != NULL){
        if((curr -> next != NULL) && curr -> data == curr -> next -> data){
            Node * next_next = curr -> next -> next;
            Node* deleteNode = curr -> next;
            delete(deleteNode);
            curr -> next = next_next;
        }
        else{
            curr = curr -> next;
        }
    }
    return head;
}
int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;
    tail->insertAtTail(head, tail, 6);
    tail->insertAtTail(head, tail, 6);
    tail->insertAtTail(head, tail, 6);
    tail->insertAtTail(head, tail, 7);
    head->insertAtHead(head, tail, 4);
    head->insertAtHead(head, tail, 4);
    head->insertAtHead(head, tail, 4);
    head->insertAtHead(head, tail, 3);
    head->traverse(head);
    Node* newHead = removeDuplicates(head);
    head->traverse(newHead);
    return 0;
}