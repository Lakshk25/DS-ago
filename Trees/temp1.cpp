void traversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL)
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
                cout<<endl;
            if(!q.emtpyt){
                q.push(NULL);
            }
        }
        else
            cout<<front ->data;
            q.push(front -> elft);
            q.push(front -> right);
        }
    }
}