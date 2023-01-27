/*

    calculate how many adjacent nodes make sum equal to K

    to do this travers nodes and store data till leaf nodes(NULL) and return now traverse vector end to start if count == k
    increase count  

*/

class Solution{
    void solve(Node* root , int k , vector<int> path , int &count){
        if(root == NULL){
            return;
        }
        // push data to vector
        path.push_back(root -> data);
        solve(root -> left , k , path , count);
        solve(root -> right , k , path , count);
        
        int n = path.size();
        int sum = 0;
        for(int i=n-1; i>=0; i--){
            sum += path[i];
            // check if sum == k
            if(sum == k)
                count++;
        }
        path.pop_back();    // optional if not written code works written  just to make code understandable bcoz last node automatically remove , we pass vector by value not refrence
    }
  public:
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count = 0;
        solve(root , k , path , count);
        return count;
    }
};