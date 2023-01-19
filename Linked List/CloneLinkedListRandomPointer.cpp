/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// time complexity O(n)
// space complexity O(n)

class Solution {
public:
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
    Node* copyRandomList(Node* head) {
    Node *copyHead = NULL;
    Node *copyTail = NULL;
    Node* temp = head;
        while(temp != NULL){
            insertAtTail(copyHead, copyTail, temp->val);
            temp = temp -> next;
        }
        unordered_map<Node* , Node*> mapping;

        Node* originalNode = head;
        Node* copyNode = copyHead;
        while(originalNode != NULL){
            mapping[originalNode] = copyNode;
            originalNode = originalNode -> next;
            copyNode = copyNode -> next;
        }
        copyNode = copyHead;
        originalNode = head;
        while(originalNode != NULL){
            copyNode -> random = mapping[originalNode -> random];
            originalNode = originalNode -> next;
            copyNode = copyNode -> next;
        }
        return copyHead;
    }
};



// time complexity O(n)
// space complexity O(1)

class Solution {
public:
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
    Node* copyRandomList(Node* head) {
        
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    // create clone list
    while(temp != NULL){
        insertAtTail(cloneHead , cloneTail , temp->val);
        temp = temp -> next;
    }
    
    // add clone node b/w original
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){
        Node* next = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = next;

        next = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode = next;
    }

    // copy random pointers
    temp = head;
    while(temp != NULL){
        if(temp -> next != NULL){
            temp -> next -> random = temp -> random ? 
            temp -> random -> next : temp -> random;
        }
        temp = temp -> next -> next;
    }

    // reverse all the changes
    originalNode = head;
    cloneNode = cloneHead;
    while(originalNode != NULL && cloneNode != NULL){
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;
        
        if(originalNode != NULL){
            cloneNode -> next = originalNode -> next;
        }
        cloneNode = cloneNode -> next;
    }
    return cloneHead;
    }
};