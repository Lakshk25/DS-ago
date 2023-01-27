/*

    to find longest blood line which is longest depth of tree with max sum 
    
    

*/

class Solution
{
public:
    void solve(Node* root , int len , int &maxLen , int sum , int &maxSum){
        if(root == NULL){   // means we reach at end of particular line
            if(len > maxLen){   // check if len is greater than prev len then simply increase it
                maxLen = len;
                maxSum = sum;
            }
            else if(maxLen == len){     // else check if sum is greater than max sum
                maxSum = max(maxSum , sum);
            }
            return;
        }
        sum += root -> data;
        solve(root -> left , len+1 , maxLen , sum , maxSum);
        solve(root -> right , len+1 , maxLen , sum , maxSum);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(root == NULL){
            return NULL;
        }
        int maxLen = 0;
        int len = 0;
        int sum = 0;
        int maxSum = 0;
        solve(root , len , maxLen , sum , maxSum);
        return maxSum;
    }
};