#include<iostream>
using namespace std;

void reverseString(string &str , int s){
    int e = (str.size()-1) - s;
    if(s > e){
        return;
    }
    swap(str[s] , str[e]);
    s++;
    reverseString(str , s);
}
int main(){
    string str = "laksh";
    reverseString(str , 0);
    cout<<str;
    return 0;
}