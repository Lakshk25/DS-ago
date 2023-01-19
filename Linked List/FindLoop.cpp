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
};
bool findLoop(Node *head)
{
    // space is O(n)
    if (head == NULL)
    {
        return false;
    }
    if (head->next == head)
    {
        return true;
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
Node *floydDetectLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}
Node *findLoopStart(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *intersect = floydDetectLoop(head);
    Node *slow = head;
    while (slow != intersect)
    {
        slow = slow->next;
        intersect = intersect->next;
    }
    return slow;
}
void removeLoop(Node *&head)
{
    Node *start = findLoopStart(head);
    Node *temp = start->next;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;
    tail->insertAtTail(head, tail, 6);
    tail->insertAtTail(head, tail, 7);
    head->insertAtHead(head, tail, 4);
    head->insertAtHead(head, tail, 3);
    head->traverse(head);
    tail->next = head->next;
    // if (findLoop(head))
    // {
    //     cout << "present" << endl;
    // }
    // else
    // {
    //     cout << "absent" << endl;
    // }
    // Node *newNode = floydDetectLoop(head);
    // Node *newNode = findLoopStart(head);
    // cout << newNode->data;
    removeLoop(head);
    head->traverse(head);
    return 0;
}