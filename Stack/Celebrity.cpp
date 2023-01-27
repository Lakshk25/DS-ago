//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i=0; i<n; i++){
            s.push(i);
        }
        while(s.size() != 1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(M[a][b]  == 1){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int ans = s.top();
        int celebrity = -1;
        int count = 0;
        for(int i=0; i<n; i++){
            if(M[ans][i] == 0){
                count++;
            }
        }
        if(count != n){
            return -1;
        }
        count = 0;
        for(int i=0; i<n; i++){
            if(M[i][ans] == 1){
                count++;
            }
        }
        if(count != n-1){
            return -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}


/*
    using two pointers



    
int celebrity(int M[N][N], int n)
{
    // This function returns the celebrity
    // index 0-based (if any)
 
    int i = 0, j = n - 1;
    while (i < j) {
        if (M[j][i] == 1) // j knows i
            j--;
        else // j doesnt know i so i cant be celebrity
            i++;
    }
    // i points to our celebrity candidate
    int candidate = i;
 
    // Now, all that is left is to check that whether
    // the candidate is actually a celebrity i.e: he is
    // known by everyone but he knows no one
    for (i = 0; i < n; i++) {
        if (i != candidate) {
            if (M[i][candidate] == 0
                || M[candidate][i] == 1)
                return -1;
        }
    }
    // if we reach here this means that the candidate
    // is really a celebrity
    return candidate;
}

*/