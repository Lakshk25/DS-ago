
class Solution
{
    public:
    /*
    here we simply do level order traversal and add nextRight pointer by taking front node
    */
    void connect(Node *root)
    {
       queue<Node*> q;
       q.push(root);
       
       while(!q.empty()){
           int size = q.size();
            while(size != 0){
                Node* front = q.front();
                // check if only one node on level point it to NULL
                if(size == 1){
                    q.pop();
                   front -> nextRight = NULL;
                }
                // normal flow 
                else{
                // pop to get next node (on same level left to right)
                    q.pop();
                    Node* temp = q.front();
                   front -> nextRight = temp;
                }
                // push front node childs
                if(front -> left)
                    q.push(front -> left);
                if(front -> right)
                    q.push(front -> right);
                size--;
           }
       }
    }    
};