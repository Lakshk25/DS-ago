//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool isOpen(vector<vector<int>> &m, int n , int x , int y , vector<vector<int>> visited){
        if((x < n && x >= 0) && (y < n && y >= 0) && m[x][y] == 1 && visited[x][y] == 0){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &m, int n , vector<string> &ans , string path , int x , int y , vector<vector<int>> visited){
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y] = 1;
        int newx = x;
        int newy = y;
        
        //down
        newx = x+1;
        newy = y;
        if(isOpen(m , n , newx , newy , visited)){
            path.push_back('D');
            solve(m , n , ans , path , x , y , visited);
            path.pop_back();
        }
        
        //up
        newx = x-1;
        newy = y;
        if(isOpen(m , n , newx , newy , visited)){
            path.push_back('U');
            solve(m , n , ans , path , x , y , visited);
            path.pop_back();
        }
        
        //right
        newx = x;
        newy = y+1;
        if(isOpen(m , n , newx , newy , visited)){
            path.push_back('R');
            solve(m , n , ans , path , x , y , visited);
            path.pop_back();
        }
        
        //left
        newx = x;
        newy = y-1;
        if(isOpen(m , n , newx , newy , visited)){
            path.push_back('L');
            solve(m , n , ans , path , x , y , visited);
            path.pop_back();
        }

        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0] == 0){
            return ans;
        }
        string path = "";
        int x = 0;
        int y = 0;
        vector<vector<int>> visited = m;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        solve(m , n , ans , path , x , y , visited);
        sort(ans.begin() , ans.end());
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends