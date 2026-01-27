# include<iostream>
using namespace std;
class CircularQ{
    int* arr;
    int currSize,cap;
    
    public:
    int f = 0;
    int r = -1;
    CircularQ(int size){
        currSize =0;
        cap = size;
        arr = new int[cap];
        
    }
    void push(int data){
        if(currSize == cap){
            cout<<"Circular Queue is Full \n";
            return;
        }
        else{
            r = (r+1)%cap;
            arr[r] = data;
            currSize++;

        }
    }
    void pop(){
        if(empty()){
            cout<<"Circular Queue is Full \n";
            return;
        }
        f= (f+1)%cap;
        currSize--;

    }
    int front(){
        if(currSize == cap){
            cout<<"Circular Queue is Full \n";
            return -1;
        }else{
            return arr[f];
        }
    }
    bool empty(){
        return currSize == 0;
    }
    void print(){
        for(int i = 0; i<cap;i++){
            cout<<arr[i]<<"   ";
        }
        cout<<endl;
    }
};
int main(){
    CircularQ cq(7);
    cq.push(65);
    cq.push(7);
    cq.push(23);
    cq.push(5);
    cq.push(77);
    cq.push(3);
    //cq.push(0);
    //cq.push(67);
    //cq.push(88);
    
    cout<<cq.front()<<endl;
    //cq.pop();
    //cq.pop();
    cout<<"Back of Circular Queue : ";
    cout<<cq.front()<<endl;
    cq.print();
    return 0;
}