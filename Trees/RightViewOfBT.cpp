vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> top;
    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *front = temp.first;
        int lvl = temp.second;
    
        // push 
        top[lvl] = front->data;

        if (front->left)
        {
            q.push(make_pair(front->left, lvl + 1));
        }

        if (front->right)
        {
            q.push(make_pair(front->right, lvl + 1));
        }
    }
    for (auto i : top)
    {
        ans.push_back(i.second);
    }

    return ans;
}