#include<bits/stdc++.h>

using namespace std;
vector<int> prevSmallIndex(vector<int> heights){
        stack<int> s;
        s.push(-1);
        vector<int> ans;
        for(int i=0; i<heights.size(); i++){
            while(s.top() != -1 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            ans.push_back(s.top());
            s.push(i);
        }
        return ans;
    }
    vector<int> nextSmallIndex(vector<int> heights){
        stack<int> s;
        s.push(-1);
        vector<int> ans;
        for(int i=heights.size()-1; i>=0; i--){
            while(s.top() != -1 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            ans.push_back(s.top());
            s.push(i);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
void tra(vector<int> v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }cout<<endl;
    
}
int main(){
    vector<int> v = {2 , 3 , 1 , 5 , 4 , 6};
    tra(v);
    vector<int> ans = prevSmallIndex(v);
    vector<int> ans2 = nextSmallIndex(v);
    tra(ans);
    tra(ans2);
    return 0;
}