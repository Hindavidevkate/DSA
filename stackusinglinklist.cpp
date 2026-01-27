#include <iostream>
using namespace std;

#include<list>
class List{
    list<int> l;
    public:
    void push(int val){
        l.push_front(val);
    }
    void pop(){
        l.pop_front();
    }
    int top(){
        return l.front();
    }
    int isempty(){
        return l.size() == 0;
    }
};
int main(){
    List l;
    l.push(56);
    l.push(55);
    l.push(34);
    l.push(76);
    l.pop();
    l.pop();
    l.top();
    while(!l.isempty()){
        cout<<l.top()<<"  ";
        l.pop();
    }
    

    return 0;
}
