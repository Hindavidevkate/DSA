#include <iostream> 
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data= val;
        next = NULL;
    }
};
class circularList{
    public:
    Node* head;
    Node* tail;
    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(tail == NULL){
            head = tail = newNode;
            tail -> next = head;
        }
        else{
            newNode -> next = head;
            head = newNode;
            tail -> next = head;
        }
    }
    void printCll(){
        if(head == NULL)return;
        cout<<head -> data<<" -> ";

        Node* temp = head -> next;
        while(temp != head){
            cout<<temp -> data<<" -> ";
            temp = temp-> next;
        }    
        cout<<temp -> data<<endl;
    }
    void insertAtTail(int val){

        Node* newNode = new Node(val);
        if(tail == NULL ){
            head = tail = newNode;
            tail -> next = head;
        }
        else{
            newNode -> next = head;
            tail -> next = newNode;
            tail = newNode;

        }
    }
};


int main(){
    circularList cll;
    cll.insertAtHead(6);
    cll.insertAtHead(78);
    cll.insertAtHead(9);
    cll.insertAtHead(23);
    cll.printCll();
    cll.insertAtTail(76);
    cll.insertAtTail(6);
    cll.insertAtTail(7);
    cll.insertAtTail(5);
    cll.printCll();

    return 0;
}