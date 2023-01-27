//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // pair first value for diameter and second for height we use pair to reduce time complexity from O(n2) to O(n)
    pair<int , int> solve(Node* root){
        if(root == NULL){
            pair<int , int>p = make_pair(0 , 0);    // if null diameter and height is 0
            return p;
        }
        pair<int , int> left = solve(root -> left);     // go till null
        pair<int , int> right = solve(root -> right);   // go till null
        int leftDiameter = left.first;      // check left diameter node 
        int rightDiameter = right.first;    //check right
        int height = left.second + right.second + 1;    // we use second for height (+1 to add root node)
        pair<int , int> ans;
        ans.first = max(leftDiameter , max(rightDiameter , height));    // check max of all three
        ans.second = max(left.second , right.second) + 1;   // +1 for adding root node
        return ans;
    }
    int diameter(Node* root) {
        // Your code here
        pair<int , int>ans = solve(root);
        cout<<ans.second;
        return ans.first;
    }
    
};
// same without pair
int solve(Node* root, int &ans){
        if(root == NULL){
            return 0;
        }
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        ans = max(ans, 1 + left + right);
        return 1 + max(left, right);
    }
    
    
    int diameter(Node* root) {
        int ans = 0;
        int diameterWithRoot = solve(root, ans);
        return ans;
    }

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}

// } Driver Code Ends