class Solution {
public:
    bool isMatching(char a , char b){
        if(a == '(' && b == ')'){
            return true;
        }
        else if(a == '{' && b == '}'){
            return true;
        }
        else if(a == '[' && b == ']'){
            return true;
        }
        else{
            return false;
        }
    }
    bool isValid(string s) {
        stack<char> check;
        for(int i=0; i<s.size(); i++){
            char opening = s[i];
            if(opening == '(' || opening == '{' || opening == '['){
                check.push(opening);
            }
            else{
                if(!check.empty()){
                    char closing = s[i];
                    if(isMatching(check.top() , closing)){
                        check.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(check.empty()){
            return true;
        }
        return false;
    }
};