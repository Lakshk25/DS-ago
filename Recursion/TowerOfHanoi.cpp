#include<iostream>
using namespace std;
int count = 0;
void tower(int n , string src , string mid , string dest){
    if(n == 1){
        cout<<"moved disc "<<n<<" from "<<src<<" to "<<dest<<endl;
        return;
    }
    tower(n-1 , src , dest , mid);
    cout<<"moved disc "<<n<<" from "<<src<<" to "<<dest<<endl;
    tower(n-1 , mid , src , dest);
}
int main(){
    int n = 2;
    string src = "S";
    string mid = "M";
    string dest = "D";
    tower(n , src , mid , dest);
    return 0;
}