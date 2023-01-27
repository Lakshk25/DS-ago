/*

left and right branch ki max value calculate karna he agar
dono branch kuch return kare (not NULL) to check karke max value me dalna
he including root data


and solve func return karega left or right me se jo max hoga + root data

taki dusri branch me check kare to get max value
*/


class Solution
{
public:
    int solve(Node *root, int sum, int &maxSum)
    {
        if (root == NULL)
            return INT_MIN;

        if (!root->left && !root->right)
            return root->data;

        // to get left sub tree max
        int left = solve(root->left, sum, maxSum);

        // to get right sub tree max
        int right = solve(root->right, sum, maxSum);

        // add left , right and root
        sum = left + right + root->data;

        // if left and right both exist then check max value to add
        // we do this to if half leaf node i.e.  1 2 N like nodes

        if (root->left && root->right)
            maxSum = max(maxSum, sum);

        // return max data from left or right + root data
        return (max(left, right) + root->data);
    }
    int maxPathSum(Node *root)
    {
        int maxSum = INT_MIN;
        int ans = solve(root, 0, maxSum);

        // if any branch is NULL return max value
        if (root->left == NULL || root->right == NULL)
            return max(ans, maxSum);

        return maxSum;
    }
};