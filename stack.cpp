#include<iostream>
using namespace std;
#include<vector>
class Stack{
    vector<int> v;
    public:
    //int top = -1;
    
    void push(int val){
        v.push_back(val);

    }
    void pop(){
        v.pop_back();
        
    }
    int top(){
        return v[v.size() - 1];
    }
    bool isempty(){
        return v.size() == 0;
    }
};
int main(){
    Stack s;
    s.push(6);
    s.push(4);
    s.push(5);
    s.push(62);
    s.pop();
    while(!s.isempty()){
        cout<<s.top()<<"  ";
        s.pop();
    }
    cout<<endl;
    cout<<s.top()<<endl;
    return 0;
}