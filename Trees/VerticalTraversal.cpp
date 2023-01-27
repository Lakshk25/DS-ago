/*
    for vertical order traversal we need to create number line like to access nodes
    ex.

        hd = horizontal distance e.g. number line , lvl = level (like level order traversal)

         hd lvl
        [-2][3] = 3
        [-2][2] = 4
        [1][-1] = 2
        [0][0] = 1
        [1][1] = 3... 
        for all nodes 

        it prints => 3 4 2 1 3 ... (ascending order)

        to do this we do mapping of hd with (lvl and vector([to store node data of same lvl]))

        and do same levelorder traversal 
        to create queue with pairof node  and  pair(hd , lvl);
        where first = node , second = hd , second.second = lvl

        on left we decrease hd and on right we increase hd 
        lvl always increase by +1

        and rest is same like lvlordertraversal

*/


class Solution
{
    public:
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans; // final ans

        // mapping first = hd , second(mapping first = lvl , vector)
        map<int , map<int , vector<int> > > nodes;
        // queue first for node and second.first for hd second.second for lvl
        queue<pair<Node* , pair<int , int> > > q;
        if(root == NULL){
            return ans;
        }
        // push first node which have hd = 0 , lvl = 0
        q.push(make_pair(root , make_pair(0 , 0)));
        
        while(!q.empty()){
            // take first node
            pair<Node* , pair<int , int> > temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hDist = temp.second.first;
            int level = temp.second.second;
            // push node mapping with hd 
            nodes[hDist][level].push_back(frontNode->data);
            
            if(frontNode -> left){
                q.push(make_pair(frontNode -> left , make_pair(hDist-1 , level+1)));
            }
            
            if(frontNode -> right){
                q.push(make_pair(frontNode -> right , make_pair(hDist+1 , level+1)));
            }
        }

        // here we push data from map by respective mapping [0][0] = 1 , [-2][2] = 3......
        for(auto i : nodes)
            for(auto j : i.second)
                for(auto k : j.second)
                    ans.push_back(k);
        
        return ans;        
    }
};
