#include<unordered_map>
#include<queue>
#include<list>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  
    unordered_map<int, list<int>> adj;
  
    for(int i=0 ; i<edges.size() ; i++){
        int u = edges[i].first -1;
        int v = edges[i].second -1;

        adj[u].push_back(v);
    }

    vector<int> indegree(n , 0);

    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i=0 ; i<n ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    int cnt = 0;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        cnt++;

        for(auto neighbours : adj[front]){
            indegree[neighbours]--;

            if(indegree[neighbours] == 0){
                q.push(neighbours);
            }
        }
    }

    if(cnt == n){
        return false;
    }

    return true;



}