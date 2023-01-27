class Solution {
private:
    vector<int> prevSmallIndex(vector<int> heights){
        stack<int> s;
        s.push(-1);
        vector<int> ans(heights.size());
        for(int i=0; i<heights.size(); i++){
            while(s.top() != -1 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> nextSmallIndex(vector<int> heights){
        stack<int> s;
        s.push(-1);
        vector<int> ans(heights.size());
        for(int i=heights.size()-1; i>=0; i--){
            while(s.top() != -1 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size());
        vector<int> right(heights.size());
        left = prevSmallIndex(heights);
        right = nextSmallIndex(heights);
        int area = INT_MIN;
        for(int i=0; i<heights.size(); i++){
            int length = heights[i];
            if(right[i] == -1){
                right[i] = heights.size();
            }
            int breadth = right[i] - left[i] - 1;
            int newArea = length * breadth;
            area = max(area , newArea);
        }
        return area;
    }
};