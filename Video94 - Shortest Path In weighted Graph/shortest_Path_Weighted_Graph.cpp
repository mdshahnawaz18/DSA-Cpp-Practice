#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
using namespace std;

class Graph{
public:
    unordered_map<int , list<pair<int , int>>> adj;
    
    void addEdge(int u , int v , int weight){
        pair<int , int> p = make_pair(v , weight);
        adj[u].push_back(p);
    }
    
    void print(){
        for(auto i : adj){
            cout<<i.first<<" ";
            for(auto j : i.second){
                cout<<"("<<j.first<<","<<j.second<<") ";
            }cout<<endl;
        }
    }

    void dfs(int node , unordered_map<int , bool> &visited , stack<int> &topo){
        visited[node] = true;

        for(auto neighbour : adj[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first , visited , topo);
            }
        }
        topo.push(node);
    }

    void shortestPath(int src , vector<int> &dist , stack<int> &topo){
        dist[src] = 0;

        while(!topo.empty()){
            int top = topo.top();
            topo.pop();

            if(dist[top] != INT_MAX){
                for(auto i : adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,2);
    g.addEdge(0,2,3);
    g.addEdge(0,3,4);
    g.addEdge(1,2,3);
    g.addEdge(1,5,2);
    g.addEdge(2,3,7);
    g.addEdge(3,5,-2);
    g.addEdge(4,5,4);
    
    g.print();
    
    unordered_map<int , bool> visited;
    stack<int> s;
    int n=6;
    
    for(int i=0 ; i<n ; i++){
        if(!visited[i]){
            g.dfs(i , visited , s);
        }
    }

    int src = 1;
    vector<int> dist(n , INT_MAX);

    g.shortestPath(src , dist , s);

    cout<<"Answer is : ";

    for(int i=0 ; i<dist.size() ; i++){
        if(dist[i] == INT_MAX){
            cout<<"Infinity"<<endl;
        }
        else{
            cout<<dist[i]<<endl;
        }
    }

    cout<<endl;

    return 0;
}