#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        data = val;
        prev= next = NULL;
    }
};
class DLL{
    Node* head;
    Node* tail;
    public:
    DLL(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode -> next = head;
            head -> prev =newNode;
            head = newNode;
        }




    }
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp -> data<<"<=>";
            temp = temp -> next;
        }
        cout<<" NULL  ";

    }
    void push_back(int val){
        Node* newNode = new Node(val);
        Node* temp = head;
        if(head == NULL){
            head = tail = newNode;
        }
        else{
               newNode -> prev = tail;
                tail -> next = newNode;
                tail = newNode;
            
        }
    }
    void pop_front(){
        if(head == NULL){
            cout<<"DLL is empty ! ";
            return;
        }
        Node* temp = head;
        head = head -> next;
        if(head != NULL){
            head -> prev = NULL;
        }
        temp -> next = NULL;
        delete temp;
    }
    void pop_back(){
        if(head == NULL){
            cout<<"DLL is empty ! ";
            return;
        }
        Node* temp = tail;
        tail = tail -> prev;
        if(tail != NULL){
            tail -> next = NULL;
        }
        temp -> prev = NULL;
        delete temp;
    }
};
int main(){
    DLL l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.print();
    cout<<endl;
    l.pop_back();
    l.pop_back();
    
    l.print();

    return 0;
}