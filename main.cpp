#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }

};
class List{
    Node* head;
    Node* tail;
    public:
        List(){
            head = tail = NULL;
        }
        void push_front(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = newNode;
                return;
            }
            else{
                newNode -> next = head;
                head = newNode;
            }
        }
        void push_back(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = NULL;

            }
            else{
                tail -> next = newNode;
                tail= newNode;
            }
        }
        void pop_front(){
            if(head == NULL){
                cout<<"Linked List is Empty ";
                return;
            }
            Node* temp = head;
            head = head -> next ;
            temp -> next = NULL;
            delete temp;
        }
        void printll(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp -> data<<"-> ";
                temp = temp -> next;
            }
        }
        void pop_back(){
            Node* temp = head;
            if(head == NULL){
                return;
            }
            while(temp -> next != tail){
                temp = temp -> next;
            }
            temp -> next = NULL;
            
            delete tail;
            tail = temp;
        }
        void insert(int val,int pos){
            Node* temp = head;
            
            if(pos < 0){
                cout<<"Invalid position";
            }
            if(pos == 0){
                push_front(val);
                return;
            }
            for(int i = 0;i<pos-1;i++){
                if(temp == NULL){
                cout<<"Invalid position";
                return;
            }
                temp = temp -> next;
            }
            Node* newNode = new Node(val);
            newNode -> next = temp -> next;
            temp -> next = newNode;


        }
        int search(int key){
            Node* temp = head;
            int idx = 0;
            while(temp != NULL){
                
                if(temp -> data == key){
                    return idx;
                }
                temp = temp -> next;
                idx++;
            }
            return -1;
        }
};
int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(3);
    ll.push_front(5);
    ll.push_front(6);
    ll.push_back(4);
   // ll.pop_front();
   // ll.pop_back();
   ll.insert(7,2);
    ll.printll();
    cout<<ll.search(7);
    
    
    
    
    return 0;
}