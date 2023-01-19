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
Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = curr;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    if (head->next == NULL)
    {
        return true;
    }
    // find middle
    Node *middle = findMiddle(head);

    // to reverse linked list
    Node *temp = middle->next;
    middle->next = reverse(temp);

    Node *head1 = head;
    Node *head2 = middle->next;
    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    // to make list original
    temp = middle->next;
    middle->next = reverse(temp);
    return true;
}
int main()
{
    Node *node1 = new Node(1);
    Node *head1 = node1;
    Node *tail1 = node1;
    head1->insertAtTail(head1, tail1, 2);
    head1->insertAtTail(head1, tail1, 3);
    head1->insertAtTail(head1, tail1, 3);
    head1->insertAtTail(head1, tail1, 2);
    head1->insertAtTail(head1, tail1, 1);
    head1->traverse(head1);
    bool ans = isPalindrome(head1);
    if (ans)
    {
        cout << "palindrome" << endl;
    }
    else
    {
        cout << "not palindrome" << endl;
    }
    return 0;
}