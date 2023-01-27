void solve(Node *root, Node *&pre, Node *&suc, int key, int &mini, int &maxi)
{
    if (root == NULL)
        return;

    // check for predecessor
    if (root->key < key)
    {
        // condition to get maximum value less than key
        if (root->key > mini)
            mini = root->key, pre = root;
    }

    // check for successor
    if (root->key > key)
    {
        // condition to get minimum value greater than key
        if (root->key < maxi)
            maxi = root->key, suc = root;
    }

    // normal flow to go left , right
    solve(root->left, pre, suc, key, mini, maxi);
    solve(root->right, pre, suc, key, mini, maxi);
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    // if not found any pre or suc initialise it to -1
    Node *temp = new Node(-1);
    pre = temp;
    suc = temp;
    int maxi = 10000;
    int mini = -1;
    // if pre suc present this func assign it
    solve(root, pre, suc, key, mini, maxi);
}