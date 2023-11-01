#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int> > adj;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  // For an undirected edge, add both directions.
    }

    void print() {
        for (const auto &pair : adj) {
            cout << pair.first << " -> ";
            for (int neighbor : pair.second) {
                cout << neighbor << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;
    Graph g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.print();
}
