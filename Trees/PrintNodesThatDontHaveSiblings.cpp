/* level order traversal karna he agar left ya right
    dono me se koi sa ek nhi he to ans me daal do
    or push kardo queue me for further checking
*/

vector<int> noSibling(Node* node)
{
    queue<Node*> q;
    q.push(node);
    vector<int> ans;
    
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        
        // check if left exist only
        if(front -> left && !front -> right){ 
            q.push(front -> left);
            ans.push_back(front -> left -> data);
        }
        // check if right exist only
        else if(front -> right && !front -> left){
            q.push(front -> right);
            ans.push_back(front -> right -> data);
        }
        // normal flow parent have both child
        else{
            if(front -> left)
                q.push(front -> left);
            if(front -> right)
                q.push(front -> right);
        }
    }
    // sort
    sort(ans.begin() , ans.end());
    // if all node have siblings vector is empty
    if(ans.empty())
        return {-1};
    return ans;
}