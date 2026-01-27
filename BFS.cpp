#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph{
    int v;
    list<int> *l;
    public:
        Graph(int v){
            this -> v = v;
            l = new list<int> [v];

        }
        void edge(int u, int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }
        void bfs(){
            queue<int> Q;
            vector<bool> vis(v,false);
            Q.push(0);
            vis[0] = true;
            while(Q.size() > 0){
                int u = Q.front();
                Q.pop();
                cout<< u << "   ";
                for(int  v: l[u]){
                    if(!vis[v]){
                        vis[v] = true;
                        Q.push(v);
                    }
                }
            }
            cout<<endl;
        }
        void dfsHelper(int u,vector<bool> &vis){
            cout<< u << "   ";
            vis[u] = true;
            for(int v : l[u]){
                if(!vis[v]){
                    dfsHelper(v,vis);
                }
            }
        }
        void dfs(){
            int src = 0;
            vector<bool>vis(v,false);
            dfsHelper(src,vis);
            // This loop only implement for unconnected graph
            for(int i =0 ; i<v ;i++){
                if(!vis[i]){
                    dfsHelper(i,vis);
                }
            }
            cout<<endl;
        }

        //This function are usedto detect if cycle is present in graph or not 
//This is wrong logic
    

};
int main(){
    Graph g(10);
    g.edge(0,2);
    g.edge(2,1);
    g.edge(2,5);
    g.edge(2,8);
    g.edge(5,4);
    g.edge(5,9);
    g.edge(8,3);
    g.edge(1,4);
    cout<<"This is BFS Traversal : ";
    g.bfs();
    cout<<"This is DFS Traversal : ";
    g.dfs();
    
    return 0;
}