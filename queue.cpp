#include <iostream>
#include<list>
#include<vector>

using namespace std;
class Node{
    public:
    int data;
    Node* next ;

    Node(int val){
        data= val;
        next = NULL;
    
    }
};
class Queue{
    //Queue using linked list 
    
    Node* head;
    Node* tail;
    public:
    list<int> v;
    Queue(){
        head = tail = NULL;
    }
    
    void push(int data){
       Node* newNode = new Node(data);
        if(isempty()){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
            
        }
    }
    void pop(){
        if(isempty()){
            cout<<"Link list is Empty \n";
            return;
        }
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
    int front(){
        if(isempty()){
            cout<<"Link list is Empty \n";
            return -1;
        }
        return head -> data;
    }
    bool isempty(){
        return head == NULL;
    }
    
};

int main(){
    Queue q;
    q.push(67);
    q.push(65);
    q.push(43);
    q.push(90);
    while(!q.isempty()){
        cout<<q.front()<<"   ";
        q.pop();
    }

    return 0 ;
}