#include <iostream> 

#include <vector>
#include<list>
using namespace std;

int main(){
    list<int> l = {1,2,3,4,5,6,7,8,3,2};
    cout<<"Size of Vector : "<<l.size()<<endl;
    cout<<"is List is empty or not : "<<l.empty()<<endl;
    cout<<"Front Element : "<<l.front()<<endl;
    cout<<"back Element : "<<l.back()<<endl;
    //cout<<"Front Element : "<<endl;
    l.push_back(10);
    l.push_back(8);
    for(auto it = l.begin(); it != l.end();it++){
        cout<<*(it)<<"  ";
    }
    cout<<endl;
    cout<<"To print reverse Element "<<endl;
     for(auto it = l.rbegin(); it != l.rend();it++){
        cout<<*(it)<<"  ";
    }
    cout<<endl;
    cout<<"Size of Vector : "<<l.size()<<endl;
    //cout<<"Capacity of Elements  : "<<l.insert(5)<<endl;
    
    cout<<endl;
    l.pop_back();
    l.pop_back();
    for(auto it = l.begin(); it != l.end();it++){
        cout<<*(it)<<"  ";
    }
    cout<<endl;
    cout<<"To print reverse Element "<<endl;
     for(auto it = l.rbegin(); it != l.rend();it++){
        cout<<*(it)<<"  ";
    }
    cout<<endl;
    l.pop_front();
    l.pop_back();
    for(auto it = l.begin(); it != l.end();it++){
        cout<<*(it)<<"  ";
    }
    return 0;
}