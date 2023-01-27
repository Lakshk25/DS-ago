class Solution {
  public:
    Node* createMapping(Node* root , int target , map<Node* , Node*>&nodeToParent){
        Node* targetNode = NULL;
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front -> data == target)
                targetNode = front;
            
            if(front -> left){
                nodeToParent[front -> left] = front;
                q.push(front -> left);
            }
            if(front -> right){
                nodeToParent[front -> right] = front;
                q.push(front -> right);
            }
        }
        return targetNode;
    }
    int burnTime(Node* targetNode , map<Node* , Node*>nodeToParent){
        
        int time = 0;
        map<Node* , bool>visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        bool flag = false;
        while(!q.empty()){
            
            flag = false;
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* front = q.front();
                q.pop();
                
                if(front -> left && visited[front -> left] != true){
                    flag = true;
                    q.push(front -> left);
                    visited[front -> left] = true;
                }
                if(front -> right && visited[front -> right] != true){
                    flag = true;
                    q.push(front -> right);
                    visited[front -> right] = true;
                }
                if(nodeToParent[front] && visited[nodeToParent[front]] != true){
                    flag = true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            if(flag == true)
                time++;
        }
        return time;
    }
    int minTime(Node* root, int target) 
    {
        map<Node* , Node*>nodeToParent;
        Node* targetNode = createMapping(root , target , nodeToParent);
        int ans = burnTime(targetNode , nodeToParent);
        return ans;
    }
};