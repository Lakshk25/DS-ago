class Solution {
	public:
		string FirstNonRepeating(string A){
		        unordered_map<char, int> count;
    queue<char> q;
    string str = "";
    for (int i = 0; i < A.size(); i++)
    {
        //  a
        char ch = A[i];
        q.push(ch);
        count[ch]++;

        while (!q.empty() && count[q.front()] > 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            str.push_back('#');
        }
        else
        {
            str.push_back(q.front());
        }
    }
    return str;
		}

};