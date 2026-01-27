#include<iostream> 
using namespace std;
#include<vector>
#include<list>
class Graph{
    int v;
    list<int>*l;//int * arr
    public:
    Graph(int v){
        this-> v = v;
        l = new list<int> [v];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);

    }
    void print(){
        for(int i =0 ; i<v;i++){
            cout<<i<<" : ";
            for(int negh : l[i]){
                cout<<negh << "  ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.print();

    return 0;
}