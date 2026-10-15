#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for (auto i : adj)
        {
            cout << i.first << " ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
        }
    }
};

int main()
{

    int n;
    cout << "Enter the No. of Nodes : ";
    cin >> n;

    int m;
    cout << "Enter the No. of Edges : ";
    cin >> m;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;

        cout << "Enter The Node Value which is connected " << endl;
        cin >> u >> v;

        g.addEdge(u, v, 0);
    }

    g.printAdjacencyList();

    return 0;
}