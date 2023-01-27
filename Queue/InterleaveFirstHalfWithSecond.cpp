#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void traverse(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
}
void interleave(queue<int>& q){
    stack<int> s;
    int n = q.size();
    int i = 0;
    while(i < n/2){
        s.push(q.front());
        q.pop();
        i++;
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

     i = 0;
    while(i < n/2){
        int val = q.front();
        q.pop();
        q.push(val);
        i++;
    }
    i = 0;
    while(i < n/2){
        s.push(q.front());
        q.pop();
        i++;
    }
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
        val = q.front();
        q.pop();
        q.push(val);
    }

}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    traverse(q);
    interleave(q);
    traverse(q);
    return 0;
}