#include <iostream>
using namespace std;
#include<vector>
#include<queue>
#include<list>

class Graph{
    int v;
    list<int> *l;
    public:
    Graph(int v){
        this -> v = v;
        l = new list<int> [v];
    }
    void edge(int u, int v){
        l[v].push_back(u);
        l[u].push_back(v);
    }
    bool isCycleDFS(int src,int par,vector<bool>&vis){
            vis[src] = true;
            list<int> neigh = l[src];
            for(int v: neigh){
                if(!vis[v]){
                    if(isCycleDFS(v,src,vis)){
                        return true;
                    }
                }else if(v!=par){
                    return true;
                }
            }
            return false;
        }

            bool isCycle(){
            vector<bool> vis(v,false);
            for(int i = 0; i< v;i++){
                if(!vis[i]){
                    if(isCycleDFS(i,-1,vis)){
                        return true;
                    }
                }
            }
            return false;
        }
};

int main(){
    Graph g(8);
    cout<<"Is Cycle in Graph : ";
    g.isCycle();
    return 0;
}