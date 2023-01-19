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
void insertNode(Node *&tail , int element , int data){
    if(tail == NULL){
        Node * newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        Node* curr = tail;
        while (curr -> data != element)
        {
            curr = curr -> next;
        }
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}
void deleteNode(Node* &tail , int element){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev -> next;
        while(curr -> data != element){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        if(curr == prev){
            tail = NULL;
        }
        if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}
void traverse(Node* tail){
    if(tail == NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail-> next;
    }
    while(temp != tail);
    cout<<endl;
}
int main()
{
    Node* tail = NULL;
    traverse(tail);
    insertNode(tail , 5 , 3);
    insertNode(tail , 3 , 4);
    insertNode(tail , 4 , 5);
    insertNode(tail , 5 , 6);
    insertNode(tail , 6 , 7);
    traverse(tail);
    deleteNode(tail , 7);
    traverse(tail);
    return 0;
}