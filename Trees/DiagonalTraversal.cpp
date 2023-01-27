
/*
    why we choose recursion coz in recursion we choose hd by root node to decide level
*/

void solve(Node *root,int hd,map<int,vector<int>>&nodes)

{

    if(root==NULL)
        return;

    nodes[hd].push_back(root->data);

    solve(root->left,hd+1,nodes);

    solve(root->right,hd,nodes);

    

}

vector<int> diagonal(Node *root)

{

  vector<int>ans;

  map<int,vector<int>>nodes;

  solve(root,0,nodes);

  for(auto i:nodes)
      for(auto j:i.second)
        ans.push_back(j);

  return ans;
}


/*

//  here problem is hd is decided by queue front node

vector<int> diagonal(Node *root)
{

   vector<int> ans;
        map<int , vector<int>> nodes;
        queue<pair<Node* , int>> q;
        q.push(make_pair(root , 0));
        
        while(!q.empty()){
            pair<Node* , int> temp = q.front();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            nodes[hd].push_back(frontNode -> data);
            if(frontNode -> left)
                q.push(make_pair(frontNode -> left , hd+1));
            if(frontNode -> right)
                q.push(make_pair(frontNode -> right , hd));
            q.pop();
        }
        
        for(auto i:nodes){
            for(auto j : i.second)
                ans.push_back(j);
        }

        return ans;
}

*/